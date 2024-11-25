class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // Directions for zero's possible moves on the 1D 2x3 board
        vector<vector<int>> directions = {
            {1, 3}, {0, 2, 4}, {1, 5}, 
            {0, 4}, {1, 3, 5}, {2, 4}
        };

        string target = "123450";
        string startState;

        // Convert 2D board to string representation
        for (auto& row : board) {
            for (int num : row) {
                startState += to_string(num);
            }
        }

        unordered_set<string> visited;  // Track visited states
        queue<string> queue;
        queue.push(startState);
        visited.insert(startState);

        int moves = 0;

        // BFS to solve the puzzle
        while (!queue.empty()) {
            int levelSize = queue.size();
            for (int i = 0; i < levelSize; i++) {
                string current = queue.front();
                queue.pop();

                // Check if target is reached
                if (current == target) return moves;

                int zeroPos = current.find('0');
                for (int newPos : directions[zeroPos]) {
                    string next = current;
                    swap(next[zeroPos], next[newPos]);

                    // Skip visited states
                    if (visited.count(next)) continue;

                    visited.insert(next);
                    queue.push(next);
                }
            }
            moves++;
        }

        return -1; // Unsolvable puzzle
    }
};
