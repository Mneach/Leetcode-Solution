class Solution {
public:

void bfs(vector<vector<int>>& mat, vector<vector<int>> &answer, int totalRow, int totalCol, int row, int col) {
        int moveRow[4] = {0, -1, 0, 1};
        int moveCol[4] = {-1, 0, 1, 0};

        deque<pair<int, int>> dq;
        dq.push_front({row, col});
        answer[row][col] = 0;

        while (dq.size() > 0) {
            auto [currRow, currCol] = dq.front();
            dq.pop_front();

            for (int move = 0; move < 4; move++) {
                int nextRow = currRow + moveRow[move];
                int nextCol = currCol + moveCol[move];

                if (nextRow < 0 || nextRow >= totalRow) continue;
                else if (nextCol < 0 || nextCol >= totalCol) continue;

                if (answer[currRow][currCol] + 1 < answer[nextRow][nextCol]) {
                    if (mat[nextRow][nextCol] == 0) {
                        answer[nextRow][nextCol] = 0;
                        mat[nextRow][nextCol] = -1;
                        dq.push_front({nextRow, nextCol});
                    } else {
                        answer[nextRow][nextCol] = answer[currRow][currCol] + 1;
                        dq.push_back({nextRow, nextCol});
                    }
                }
            }
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int totalRow = mat.size();
        int totalCol = mat[0].size();
        vector<vector<int>> answer(totalRow, vector<int>(totalCol, INT_MAX));

        for (int row = 0; row < totalRow; row++) {
            for (int col = 0; col < totalCol; col++) {

                if (mat[row][col] == 0) {
                    // do bfs algorithm
                    bfs(mat, answer, totalRow, totalCol, row, col);
                }
            }
        }

        return answer;
    }
};