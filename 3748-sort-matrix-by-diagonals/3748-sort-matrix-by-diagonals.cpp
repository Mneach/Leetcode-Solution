class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int totalRow = grid.size();
        int totalCol = grid[0].size();

        // calculate top right
        for (int col = 1; col < totalCol; col++) {
            int tempCol = col;
            int tempRow = 0;
            priority_queue<int, vector<int>, greater<int>> pq;

            while (tempCol < totalCol && tempRow < totalRow) {
                pq.push(grid[tempRow][tempCol]);
                tempRow++;
                tempCol++;
            }

            tempCol = col;
            tempRow = 0;
            while(pq.size() > 0) {
                int value = pq.top();
                pq.pop();

                grid[tempRow][tempCol] = value;
                tempRow++;
                tempCol++;
            }
        }

        // calculate bottom right
        for (int row = 0; row < totalRow; row++) {
            int tempRow = row;
            int tempCol = 0;
            priority_queue<int> pq;

            while (tempRow < totalRow && tempCol < totalCol) {
                pq.push(grid[tempRow][tempCol]);
                tempRow++;
                tempCol++;
            }

            tempRow = row;
            tempCol = 0;
            while(pq.size() > 0) {
                int value = pq.top();
                pq.pop();

                grid[tempRow][tempCol] = value;
                tempRow++;
                tempCol++;
            }
        }

        return grid;
    }
};