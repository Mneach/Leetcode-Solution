class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        int total_candies = 0;
        const int n = status.size();
        
        // Track box states
        vector<bool> can_open(n);       // Can we open the box (have key)?
        vector<bool> has_box(n);        // Do we possess this box?
        vector<bool> processed(n);      // Have we collected candies from this box?
        
        // Initialize boxes we can initially open
        queue<int> boxes_to_process;
        
        // Set up initial state
        for (int i = 0; i < n; ++i) {
            can_open[i] = (status[i] == 1);
        }
        
        // Process initial boxes
        for (int box : initialBoxes) {
            has_box[box] = true;
            if (can_open[box]) {
                boxes_to_process.push(box);
                processed[box] = true;
                total_candies += candies[box];
            }
        }
        
        // Process boxes in BFS manner
        while (!boxes_to_process.empty()) {
            int current_box = boxes_to_process.front();
            boxes_to_process.pop();
            
            // Collect keys from current box
            for (int key : keys[current_box]) {
                if (!can_open[key]) {
                    can_open[key] = true;
                    // If we have this box and haven't processed it yet
                    if (has_box[key] && !processed[key]) {
                        boxes_to_process.push(key);
                        processed[key] = true;
                        total_candies += candies[key];
                    }
                }
            }
            
            // Collect contained boxes from current box
            for (int new_box : containedBoxes[current_box]) {
                if (!has_box[new_box]) {
                    has_box[new_box] = true;
                    // If we can open this box and haven't processed it yet
                    if (can_open[new_box] && !processed[new_box]) {
                        boxes_to_process.push(new_box);
                        processed[new_box] = true;
                        total_candies += candies[new_box];
                    }
                }
            }
        }
        
        return total_candies;
    }
};