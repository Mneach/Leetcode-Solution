class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {

        vector<int> answer;

        int totalRow = grid.size();
        int totalCol = grid[0].size();

        for (int row = 0; row < totalRow; row++) {
            if (row % 2 == 0) {
                // start from 0

                for (int col = 0; col < totalCol; col += 2) {
                    answer.push_back(grid[row][col]);
                }
            } else {
                int start = 0;

                if (totalCol % 2 == 0) {
                    start = totalCol - 1;
                } else {
                    start = totalCol - 2;
                }

                for (int col = start; col >= 0; col -= 2) {
                    answer.push_back(grid[row][col]);
                }
            }
        }

        return answer;
    }
};