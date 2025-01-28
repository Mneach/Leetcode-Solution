class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int answer = 0;
        int totalRow = grid.size();
        int totalCol = grid[0].size();
        int moveRow[4] = {0,-1,0,1};
        int moveCol[4] = {-1,0,1,0};

        for (int row = 0; row < totalRow; row++) {
            for (int col = 0; col < totalCol; col++) {
                if (grid[row][col] > 0) {
                    int total = 0;
                    queue<pair<int,int>> q;
                    q.push({row, col});

                    while(!q.empty()) {
                        auto [row, col] = q.front();
                        q.pop();

                        total += grid[row][col];
                        grid[row][col] = 0;

                        for (int move = 0; move < 4; move++) {
                            int nextRow = moveRow[move] + row;
                            int nextCol = moveCol[move] + col;

                            if (nextRow < 0 || nextRow >= totalRow) continue;
                            else if(nextCol < 0 || nextCol >= totalCol) continue;
                            else if (grid[nextRow][nextCol] == 0) continue;

                            q.push({nextRow, nextCol});
                        }
                    }

                    answer = max(answer, total);
                }
            }
        }

        return answer;

    }
};