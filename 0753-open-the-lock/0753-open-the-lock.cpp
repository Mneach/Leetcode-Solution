class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // Precompute wheel rotations
        const vector<pair<char, char>> wheelTransitions = {
            {'0', '1'}, {'1', '2'}, {'2', '3'}, {'3', '4'}, {'4', '5'},
            {'5', '6'}, {'6', '7'}, {'7', '8'}, {'8', '9'}, {'9', '0'}
        };
        
        unordered_map<char, char> nextSlot, prevSlot;
        for (const auto& transition : wheelTransitions) {
            nextSlot[transition.first] = transition.second;
            prevSlot[transition.second] = transition.first;
        }
        
        unordered_set<string> visited(deadends.begin(), deadends.end());
        queue<string> q;
        
        const string initial = "0000";
        if (visited.count(initial)) return -1;
        
        q.push(initial);
        visited.insert(initial);
        int turns = 0;
        
        while (!q.empty()) {
            int levelSize = q.size();
            
            for (int i = 0; i < levelSize; ++i) {
                string current = q.front();
                q.pop();
                
                if (current == target) {
                    return turns;
                }
                
                // Generate all possible next combinations
                for (int j = 0; j < 4; ++j) {
                    // Rotate wheel forward
                    string next = current;
                    next[j] = nextSlot[next[j]];
                    if (!visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                    
                    // Rotate wheel backward
                    string prev = current;
                    prev[j] = prevSlot[prev[j]];
                    if (!visited.count(prev)) {
                        visited.insert(prev);
                        q.push(prev);
                    }
                }
            }
            
            ++turns;
        }
        
        return -1;
    }
};