class Solution {
public:
    const int INITIAL_VALUE = -1e7;

    int dfs(vector<vector<int>>& coins, vector<vector<vector<int>>>& answer, int row, int col, int k) {
        int totalRow = coins.size();
        int totalCol = coins[0].size();

        if (row < 0 || row >= totalRow) {
            return INITIAL_VALUE;
        }
        else if (col < 0 || col >= totalCol) {
            return INITIAL_VALUE;
        }
        else if (answer[row][col][k] != INITIAL_VALUE) {
            return answer[row][col][k];
        }

        int currentCoin = coins[row][col];
        if (row == totalRow - 1 && col == totalCol - 1) {

            if (currentCoin >= 0) {
                answer[row][col][k] = currentCoin;
            } else {
                if (k > 0) {
                    answer[row][col][k] = max(currentCoin, 0);
                } else {
                    answer[row][col][k] = currentCoin;
                }
            }

            return answer[row][col][k];
        } else {
            int rightMove = INT_MIN;
            int bottomMove = INT_MIN;

            if (currentCoin >= 0) {
                // we dont need to use the special ability
                rightMove = dfs(coins, answer, row, col + 1, k) + currentCoin;
                bottomMove = dfs(coins, answer, row + 1, col, k) + currentCoin;
            } else {
                if (k > 0) {
                    // we can use our special ability
                    rightMove = dfs(coins, answer, row, col + 1, k - 1);
                    bottomMove = dfs(coins, answer, row + 1, col, k - 1);
                }

                // choose not using special ability and try to compare if we are using special ability
                rightMove = max(rightMove, dfs(coins, answer, row, col + 1, k) + currentCoin);
                bottomMove = max(bottomMove, dfs(coins, answer, row + 1, col, k) + currentCoin);
            }

            answer[row][col][k] = max(rightMove, bottomMove);
            return answer[row][col][k];
        }
    }

    int maximumAmount(vector<vector<int>>& coins) {
        int totalRow = coins.size();
        int totalCol = coins[0].size();
        vector<vector<vector<int>>> answer(
            totalRow,
            vector<vector<int>>(totalCol, vector<int>(3, INITIAL_VALUE)));

        return dfs(coins, answer, 0, 0, 2);
    }
};