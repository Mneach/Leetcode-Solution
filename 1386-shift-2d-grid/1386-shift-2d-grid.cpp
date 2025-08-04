class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m));

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                int newCol = (col + k) % m;
                int newRow = (row + (col + k) / m) % n; 
                ans[newRow][newCol] = grid[row][col];
            }
        }
        return ans;
    }
};