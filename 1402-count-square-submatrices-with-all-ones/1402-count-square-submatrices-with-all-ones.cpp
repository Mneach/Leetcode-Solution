class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
if (matrix.empty()) return 0;

  int m = matrix.size();
  int n = matrix[0].size();

  int totalSquares = 0;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
	if (matrix[i][j] == 0) continue;

      int left = (i == 0) ? 0 : matrix[i-1][j];
      int top = (j == 0) ? 0 :  matrix[i][j-1];
      int lefttop = (i == 0 || j == 0) ? 0 : matrix[i-1][j-1];

      matrix[i][j] = min(min(left, top), lefttop) + 1;

      totalSquares += matrix[i][j];
    }
  }

  return totalSquares;

    }
};