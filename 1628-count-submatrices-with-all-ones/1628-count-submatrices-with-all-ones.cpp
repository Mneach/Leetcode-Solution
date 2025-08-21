class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> heights(m, 0);
        int result = 0;
        
        for (int i = 0; i < n; i++) {
            // Update heights for current row
            for (int j = 0; j < m; j++) {
                heights[j] = mat[i][j] == 0 ? 0 : heights[j] + 1;
            }
            
            // Use monotonic stack to count submatrices
            stack<int> st;
            vector<int> dp(m, 0); // dp[j] = number of submatrices ending at column j
            
            for (int j = 0; j < m; j++) {
                // Pop until we find a column with smaller height
                while (!st.empty() && heights[st.top()] >= heights[j]) {
                    st.pop();
                }
                
                if (st.empty()) {
                    dp[j] = heights[j] * (j + 1);
                } else {
                    int prev = st.top();
                    dp[j] = dp[prev] + heights[j] * (j - prev);
                }
                
                result += dp[j];
                st.push(j);
            }
        }
        
        return result;
    }
};