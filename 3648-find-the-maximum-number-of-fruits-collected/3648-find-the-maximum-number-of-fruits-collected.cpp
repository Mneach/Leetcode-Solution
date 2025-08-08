class Solution {
private:
    int calculatePathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> prev(n, INT_MIN), current(n, INT_MIN);
        
        // Initialize starting point (top-right corner)
        prev[n - 1] = grid[0][n - 1];
        
        for (int row = 1; row < n - 1; ++row) {
            for (int col = max(n - 1 - row, row + 1); col < n; ++col) {
                int max_prev = prev[col];
                if (col > 0) max_prev = max(max_prev, prev[col - 1]);
                if (col < n - 1) max_prev = max(max_prev, prev[col + 1]);
                
                current[col] = max_prev + grid[row][col];
            }
            swap(prev, current);
        }
        
        return prev[n - 1];
    }
    
    void transposeMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        if (n == 0) return 0;
        
        // Sum the main diagonal
        int total = 0;
        for (int i = 0; i < n; ++i) {
            total += fruits[i][i];
        }
        
        // Calculate first path (top-right to bottom-right)
        total += calculatePathSum(fruits);
        
        // Transpose the matrix for the second path
        transposeMatrix(fruits);
        
        // Calculate second path (now top-left to bottom-left)
        total += calculatePathSum(fruits);
        
        return total;
    }
};