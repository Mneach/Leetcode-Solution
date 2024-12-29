class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {

        int answer = 0;
        int totalRow = grid.size();
        int totalCol = grid[0].size();

        for(int col = 0; col < totalCol; col++){
            int current = grid[0][col];
            // cout << current << " ";
            for (int row = 1; row < totalRow; row++) {

                if (grid[row][col] <= current) {
                    int result = (current + 1) - grid[row][col];
                    answer += result;
                    grid[row][col] = current + 1;
                }
                current = grid[row][col];
                // cout << grid[row][col] << " ";
            }
            // cout << endl;
        }

        return answer;
    }
};