class Solution {
public:
    int numDecodings(string s) {
        
        if(s.length() == 1 && s[0] == '0') return 0;
        
        long long int dp[101];
        
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i < 92; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        int answer = 1;
        
        int totalValid = 1;
        for(int i = 1; i < s.length(); i++){
            
            if(s[i] == '0' && s[i - 1] == '0'){
                answer = 0;
                break;
            }
            
            if(s[i - 1] == '0' && i == 1){
                answer = 0;
                totalValid = 0;
                continue;
            }else if(s[i - 1] == '0'){
                totalValid = 1;
                continue;
            }
            
            
            string currentNumber = s.substr(i - 1, 2);
            
            if(currentNumber > "26" && currentNumber[1] == '0'){
                answer = 0;
                break;
            }
            
            if(currentNumber > "26" || s[i] == '0'){
                if(s[i] == '0') totalValid--;
                
                answer *= dp[totalValid];
                totalValid = 1;
            }else{
                totalValid++;
            }
        }
        
        if(totalValid > 0){
            answer *= dp[totalValid];
        }
        
        return answer;
    }
};