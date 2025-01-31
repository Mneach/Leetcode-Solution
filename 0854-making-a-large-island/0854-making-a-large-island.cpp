/*

Intuition : 
1. Grouping the island
2. Try all possibility, change from 0 to 1, there will be 2 cases:
   - check 4 directional from current position
   - if there is a island, combine to 1 groups

*/

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        // grouping the island by using bfs algorithm
        vector<vector<pair<int,int>>> bucket(grid.size(), vector<pair<int,int>>(grid[0].size(), make_pair(0,0)));
        int group = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j= 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1 && visited[i][j] == false) {
                    int moveRow[4] = {-1,0,1,0};
                    int moveCol[4] = {0,-1,0,1};
                    queue<pair<int,int>> q;
                    vector<pair<int,int>> path;
                    path.push_back({i, j});
                    visited[i][j] = true;
                    q.push({i, j});
                    int total = 0;

                    while (!q.empty()) {
                        auto [row, col] = q.front();
                        q.pop();
                        total++;

                        for (int move = 0; move < 4; move++) {
                            int nextRow = moveRow[move] + row;
                            int nextCol = moveCol[move] + col;

                            if (nextRow < 0 || nextRow >= grid.size()) continue;
                            else if (nextCol < 0 || nextCol >= grid.size()) continue;
                            else if (grid[nextRow][nextCol] == 0) continue;
                            else if (visited[nextRow][nextCol] == true) continue;
                            
                            path.push_back({nextRow, nextCol});
                            visited[nextRow][nextCol] = true;
                            q.push({nextRow,nextCol});
                        }
                    }

                    for (auto data : path) {
                        bucket[data.first][data.second] = make_pair(total, group);
                    }
                    group++;
                }
            }
        }

        int answer = 0;

        for (int i = 0; i < bucket.size(); i++) {
            for (int j = 0; j < bucket[i].size(); j++) {
                if (bucket[i][j].first != 0) {
                    answer = max(answer, bucket[i][j].first);
                } else {

                    pair<int,int> top = i == 0 ? make_pair(-1,0) : bucket[i - 1][j];
                    pair<int,int> bottom = i == bucket.size() - 1 ? make_pair(-1,0) : bucket[i + 1][j];
                    pair<int,int> left = j == 0 ? make_pair(-1,0) : bucket[i][j - 1];
                    pair<int,int> right = j == bucket[0].size() - 1 ? make_pair(-1,0) : bucket[i][j + 1];

                    priority_queue<pair<int,int>> pq;
                    if (top.first != -1) pq.push(top);
                    if (bottom.first != -1) pq.push(bottom);
                    if (left.first != -1) pq.push(left);
                    if (right.first != -1) pq.push(right);

                    unordered_map<int,int> ump;
                    ump[top.second] = max(ump[top.second], top.first);
                    ump[bottom.second] = max(ump[bottom.second], bottom.first);
                    ump[left.second] = max(ump[left.second], left.first);
                    ump[right.second] = max(ump[right.second], right.first);

                    int combine = 0;
                    for (auto data : ump) combine += data.second;

                    answer = max(answer, combine + 1);
                }
            }
        }

        return answer;
    }
};