class Solution {
public:
    
    int dfs(vector<vector<int>> &dp, int currentIndex, char prev, string &s, int k){
        if(currentIndex >= s.length()){
            return 0;
        }
        
        if(dp[prev - 'a'][currentIndex] != 0){
            return dp[prev - 'a'][currentIndex];
        }
        
        // take it or leave it
        
        if(abs(s[currentIndex] - prev) <= k){
            // take it
            dp[prev - 'a'][currentIndex] = max(dp[prev - 'a'][currentIndex], dfs(dp, currentIndex + 1, s[currentIndex], s , k)) + 1;
        }
        
        dp[prev - 'a'][currentIndex] = max(dp[prev - 'a'][currentIndex], dfs(dp, currentIndex + 1, prev, s , k));        
        
        return dp[prev - 'a'][currentIndex];
    }
    
    int longestIdealString(string s, int k) {
        
        vector<vector<int>> dp(26, vector<int>(s.length(), 0));
        
        int answer = 0;
        for(int i = 0; i < s.length(); i++){
            answer = max(answer, dfs(dp, i + 1, s[i], s , k) + 1);
        }
        
        
        return answer;
    }
};