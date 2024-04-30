class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int maxarea = 0;
        vector<int> dp(matrix[0].size(), 0);
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
            }
            vector<int> stack = {-1};
            int maxareaTemp = 0;
            for (int i = 0; i < dp.size(); ++i) {
                while (stack.back() != -1 && dp[stack.back()] >= dp[i]) {
                    int height = dp[stack.back()];
                    stack.pop_back();
                    maxareaTemp = max(maxareaTemp, height * (i - stack.back() - 1));
                }
                stack.push_back(i);
            }
            while (stack.back() != -1) {
                int height = dp[stack.back()];
                stack.pop_back();
                maxareaTemp = max(maxareaTemp, height * (static_cast<int>(dp.size()) - stack.back() - 1));
            }
            
            maxarea = max(maxarea, maxareaTemp);
        } 
        return maxarea;
    }
};