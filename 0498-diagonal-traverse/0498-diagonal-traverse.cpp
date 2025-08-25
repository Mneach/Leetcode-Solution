class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return {};
    }
    
    const int rows = matrix.size();
    const int cols = matrix[0].size();
    vector<int> result;
    result.reserve(rows * cols);  // Pre-allocate for efficiency
    
    // Traverse each diagonal (sum represents i + j)
    for (int sum = 0; sum < rows + cols - 1; ++sum) {
        bool goingUp = (sum % 2 == 0);  // Even diagonals go up-right
        
        if (goingUp) {
            // Start from bottom-left of diagonal, go up-right
            for (int row = min(sum, rows - 1); row >= 0 && sum - row < cols; --row) {
                int col = sum - row;
                result.push_back(matrix[row][col]);
            }
        } else {
            // Start from top-right of diagonal, go down-left
            for (int row = max(0, sum - cols + 1); row <= sum && row < rows; ++row) {
                int col = sum - row;
                result.push_back(matrix[row][col]);
            }
        }
    }
    
    return result;
}
};