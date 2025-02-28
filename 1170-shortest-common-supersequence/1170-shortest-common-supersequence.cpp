class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int size1 = str1.length();
        int size2 = str2.length();

        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));

        for (int row = 0; row <= size1; row++) {
            dp[row][0] = row;
        }

        for (int col = 0; col <= size2; col++) {
            dp[0][col] = col;
        }

        for (int row = 1; row <= size1; row++) {
            for (int col = 1; col <= size2; col++) {

                if (str1[row - 1] == str2[col - 1]) {
                    dp[row][col] = dp[row - 1][col - 1] + 1;
                } else {
                    dp[row][col] = min(dp[row - 1][col], dp[row][col - 1]) + 1;
                }
            }
        }

        string answer = "";

        // backtrack 
        int row = size1;
        int col = size2;

        while (row > 0 && col > 0) {
            if (str1[row - 1] == str2[col - 1]) {
                answer += str1[row - 1];
                row--;
                col--;
            } else if (dp[row - 1][col] < dp[row][col - 1]) {
                answer += str1[row - 1];
                row--;
            } else {
                answer += str2[col - 1];
                col--;
            }
        }

        while (row > 0) {
            answer += str1[row - 1];
            row--;
        }

        while (col > 0) {
            answer += str2[col - 1];
            col--;
        }

        reverse(answer.begin(), answer.end());
        
        return answer;
    }
};