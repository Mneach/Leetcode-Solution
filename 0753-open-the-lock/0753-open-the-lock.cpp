class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<char, char> nextSlot = {
            {'0', '1'}, 
            {'1', '2'}, 
            {'2', '3'}, 
            {'3', '4'}, 
            {'4', '5'},
            {'5', '6'}, 
            {'6', '7'}, 
            {'7', '8'}, 
            {'8', '9'}, 
            {'9', '0'}
        };
        unordered_map<char, char> prevSlot = {
            {'0', '9'}, 
            {'1', '0'}, 
            {'2', '1'}, 
            {'3', '2'}, 
            {'4', '3'},
            {'5', '4'}, 
            {'6', '5'}, 
            {'7', '6'}, 
            {'8', '7'}, 
            {'9', '8'}
        };
        
        unordered_set<string> visitedCombination(deadends.begin(), deadends.end());
        
        queue<string> pendingCombination;
        
        if(visitedCombination.find("0000") != visitedCombination.end()) return -1;
        
        pendingCombination.push("0000");
        visitedCombination.insert("0000");
        int turns = 0;
        
        while(pendingCombination.empty() == false){
            for(int depth = pendingCombination.size(); depth > 0; --depth){
                string current = pendingCombination.front();
                pendingCombination.pop();

                cout << current << endl;
                if (current == target) {
                    return turns;
                }

                for(int i = 0; i < 4; i++){
                    string newCombination = current;
                    newCombination[i] = nextSlot[newCombination[i]];

                    if (visitedCombination.find(newCombination) == visitedCombination.end()) {
                        pendingCombination.push(newCombination);
                        visitedCombination.insert(newCombination);
                    }

                    newCombination = current;
                    newCombination[i] = prevSlot[newCombination[i]];
                    if (visitedCombination.find(newCombination) == visitedCombination.end()) {
                        pendingCombination.push(newCombination);
                        visitedCombination.insert(newCombination);
                    }
                }
            }
            turns += 1;
        }
        
        return -1;
    }
};