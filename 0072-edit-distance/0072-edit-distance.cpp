class Solution {
public:
    
    int checkSame(char x , char y){
        if(x == y) return 0;
        else return 1;
    }
    
    int minDistance(string word1, string word2) {
        int sizeWord1 = word1.length();
        int sizeWord2 = word2.length();
        vector<vector<int>> dp(sizeWord1 + 1, vector<int>(sizeWord2 + 1, 0));
        
        for(int i = 1; i <= sizeWord1; i++){
            dp[i][0] = i;
        }        
        
        for(int i = 1; i <= sizeWord2; i++){
            dp[0][i] = i;
        }
        
        for(int i = 1; i <= sizeWord1; i++){
            for(int j = 1; j <= sizeWord2; j++){
                if(word1[i - 1] != word2[j - 1])  dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                else dp[i][j] = dp[i - 1][j - 1];
            }
        }   
        return dp[sizeWord1][sizeWord2];
    }
};