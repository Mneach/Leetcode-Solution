class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int totalRow = grid.size();
        int totalCol = grid[0].size();
        int moveX[4] = {0,0,1,-1};
        int moveY[4] = {1,-1,0,0};

        vector<vector<int>> answer(totalRow, vector<int>(totalCol, INT_MAX));

        // do bfs algorithm
        deque<pair<int,int>> dq; 
        dq.push_front({0,0});
        answer[0][0] = 0;

        while (dq.size() > 0) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (int i = 0; i < 4; i++) {
                int nextX = x + moveX[i];
                int nextY = y + moveY[i];

                if (nextX < 0 || nextX >= totalRow) continue;
                else if(nextY < 0 || nextY >= totalCol) continue;

                  int cost = 1;
                  if (grid[x][y] == i + 1) {
                    cost = 0;
                  }

                if(answer[x][y] + cost < answer[nextX][nextY]) {

                    answer[nextX][nextY] = answer[x][y] + cost;

                    if(cost == 1) {
                        dq.push_back({nextX, nextY});
                    } else {
                        dq.push_front({nextX, nextY});
                    }
                }
            }
        }

        return answer[totalRow - 1][totalCol - 1];
    }
};
