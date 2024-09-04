class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Directions: North, East, South, West
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dirIndex = 0;  // Start facing North
        int x = 0, y = 0, maxDist = 0;
        
        // Insert obstacles into a set for O(1) lookups
        set<pair<int, int>> obstacleSet;
        for (const auto& obstacle : obstacles) {
            obstacleSet.insert({obstacle[0], obstacle[1]});
        }
        
        // Process each command
        for (int command : commands) {
            if (command == -2) {
                // Turn left 90 degrees
                dirIndex = (dirIndex + 3) % 4;
            } else if (command == -1) {
                // Turn right 90 degrees
                dirIndex = (dirIndex + 1) % 4;
            } else {
                // Move forward in the current direction
                for (int step = 0; step < command; ++step) {
                    int nextX = x + directions[dirIndex].first;
                    int nextY = y + directions[dirIndex].second;
                    
                    if (obstacleSet.count({nextX, nextY})) {
                        break;  // Stop if an obstacle is encountered
                    }
                    
                    x = nextX;
                    y = nextY;
                }
                // Update the maximum Euclidean distance squared
                maxDist = max(maxDist, x * x + y * y);
            }
        }
        
        return maxDist;
    }
};
