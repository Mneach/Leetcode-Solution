class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> boardCopy(board.size());
        copy(board.begin(), board.end(), boardCopy.begin());

        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[row].size(); col++) {
                int currentCell = board[row][col];
                int live = 0;

                if (row > 0 && col > 0) {
                    // get top left
                    live += boardCopy[row - 1][col - 1];
                } 

                if (row > 0) {
                    // get top
                    live += boardCopy[row - 1][col];
                }

                if (row > 0 && col + 1 < board[row].size()) {
                    // get topRight
                    live += boardCopy[row - 1][col + 1];
                }

                if (col + 1 < board[row].size()) {
                    // get right
                    live += boardCopy[row][col + 1];
                }

                if (row + 1 < board.size() && col + 1 < board[row].size()) {
                    // get right bottom
                    live += boardCopy[row + 1][col + 1];
                }

                if (row + 1 < board.size()) {
                    // get bottom
                    live += boardCopy[row + 1][col];
                }

                if (row + 1 < board.size() && col > 0) {
                    // get bottom left
                    live += boardCopy[row + 1][col - 1];
                }

                if (col > 0) {
                    // get left
                    live += boardCopy[row][col -1];
                }

                if (live < 2) {
                    board[row][col] = 0;
                } else if (live == 3 && currentCell == 0) {
                    board[row][col] = 1;
                } else if (live > 3) {
                    board[row][col] = 0;
                }
            }
        }
    }
};