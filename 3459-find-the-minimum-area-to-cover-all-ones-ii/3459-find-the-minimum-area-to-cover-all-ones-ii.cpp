class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = INT_MAX;
        
        // Helper lambda to calculate minimum area of rectangle enclosing all ones
        auto getMinArea = [&](int st_i, int en_i, int st_j, int en_j) {
            int start_row = INT_MAX, end_row = -1, start_col = INT_MAX, end_col = -1;
            bool found = false;
            
            for (int i = st_i; i <= en_i; i++) {
                for (int j = st_j; j <= en_j; j++) {
                    if (grid[i][j] == 1) {
                        start_row = min(start_row, i);
                        end_row = max(end_row, i);
                        start_col = min(start_col, j);
                        end_col = max(end_col, j);
                        found = true;
                    }
                }
            }
            return found ? (end_row - start_row + 1) * (end_col - start_col + 1) : 0;
        };
        
        // Pattern 1: Horizontal then vertical cut
        for (int i = 0; i < m; i++) {
            int area1 = getMinArea(0, i, 0, n - 1);
            for (int j = 0; j < n; j++) {
                int area2 = getMinArea(i + 1, m - 1, 0, j);
                int area3 = getMinArea(i + 1, m - 1, j + 1, n - 1);
                ans = min(ans, area1 + area2 + area3);
            }
        }
        
        // Pattern 2: Vertical then horizontal cut (left)
        for (int j = 0; j < n; j++) {
            int area1 = getMinArea(0, m - 1, 0, j);
            for (int i = 0; i < m; i++) {
                int area2 = getMinArea(0, i, j + 1, n - 1);
                int area3 = getMinArea(i + 1, m - 1, j + 1, n - 1);
                ans = min(ans, area1 + area2 + area3);
            }
        }
        
        // Pattern 3: Vertical then horizontal cut (right)
        for (int j = n - 1; j >= 0; j--) {
            int area1 = getMinArea(0, m - 1, j + 1, n - 1);
            for (int i = 0; i < m; i++) {
                int area2 = getMinArea(0, i, 0, j);
                int area3 = getMinArea(i + 1, m - 1, 0, j);
                ans = min(ans, area1 + area2 + area3);
            }
        }
        
        // Pattern 4: Horizontal cut at bottom
        for (int i = m - 1; i >= 0; i--) {
            int area1 = getMinArea(i + 1, m - 1, 0, n - 1);
            for (int j = 0; j < n; j++) {
                int area2 = getMinArea(0, i, 0, j);
                int area3 = getMinArea(0, i, j + 1, n - 1);
                ans = min(ans, area1 + area2 + area3);
            }
        }
        
        // Pattern 5: Three horizontal strips
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                int area1 = getMinArea(0, i, 0, n - 1);
                int area2 = getMinArea(i + 1, j, 0, n - 1);
                int area3 = getMinArea(j + 1, m - 1, 0, n - 1);
                ans = min(ans, area1 + area2 + area3);
            }
        }
        
        // Pattern 6: Three vertical strips
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int area1 = getMinArea(0, m - 1, 0, i);
                int area2 = getMinArea(0, m - 1, i + 1, j);
                int area3 = getMinArea(0, m - 1, j + 1, n - 1);
                ans = min(ans, area1 + area2 + area3);
            }
        }
        
        return ans;
    }
};