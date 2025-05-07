#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct State {
    int x;
    int y;
    int time;
    State(int x, int y, int time) : x(x), y(y), time(time) {}
};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        const int rows = moveTime.size();
        if (rows == 0) return 0;
        const int cols = moveTime[0].size();
        
        // Directions: down, up, right, left
        const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        // Min time matrix initialized with infinity
        vector<vector<int>> minTime(rows, vector<int>(cols, INT_MAX));
        minTime[0][0] = 0;  // Starting point
        
        // Visited matrix
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        // Priority queue with custom comparator
        auto cmp = [](const State& a, const State& b) { return a.time > b.time; };
        priority_queue<State, vector<State>, decltype(cmp)> pq(cmp);
        pq.emplace(0, 0, 0);
        
        while (!pq.empty()) {
            State current = pq.top();
            pq.pop();
            
            // Skip if already visited with a better time
            if (visited[current.x][current.y]) continue;
            visited[current.x][current.y] = true;
            
            // Explore neighbors
            for (const auto& dir : directions) {
                int nx = current.x + dir.first;
                int ny = current.y + dir.second;
                
                // Check boundaries
                if (nx < 0 || nx >= rows || ny < 0 || ny >= cols) continue;
                
                // Calculate new time: max(current time, moveTime at new cell) + 1
                int newTime = max(current.time, moveTime[nx][ny]) + 1;
                
                // Update if found a better path
                if (newTime < minTime[nx][ny]) {
                    minTime[nx][ny] = newTime;
                    pq.emplace(nx, ny, newTime);
                }
            }
        }
        
        return minTime[rows - 1][cols - 1];
    }
};