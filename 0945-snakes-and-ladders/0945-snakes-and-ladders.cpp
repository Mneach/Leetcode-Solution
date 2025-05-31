#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        
        // Precompute cell positions (label to (row, col))
        vector<pair<int, int>> cell_positions(n * n + 1);
        bool left_to_right = true;
        int label = 1;
        
        for (int row = n - 1; row >= 0; --row) {
            if (left_to_right) {
                for (int col = 0; col < n; ++col) {
                    cell_positions[label++] = {row, col};
                }
            } else {
                for (int col = n - 1; col >= 0; --col) {
                    cell_positions[label++] = {row, col};
                }
            }
            left_to_right = !left_to_right;
        }
        
        // BFS initialization
        vector<int> distances(n * n + 1, -1);
        distances[1] = 0;
        queue<int> bfs_queue;
        bfs_queue.push(1);
        
        // BFS loop
        while (!bfs_queue.empty()) {
            int current = bfs_queue.front();
            bfs_queue.pop();
            
            // Explore all possible moves (1-6)
            int max_next = min(current + 6, n * n);
            for (int next = current + 1; next <= max_next; ++next) {
                auto [row, col] = cell_positions[next];
                int destination = board[row][col] == -1 ? next : board[row][col];
                
                if (distances[destination] == -1) {
                    distances[destination] = distances[current] + 1;
                    bfs_queue.push(destination);
                    
                    // Early exit if we reach the target
                    if (destination == n * n) {
                        return distances[destination];
                    }
                }
            }
        }
        
        return distances[n * n];
    }
};