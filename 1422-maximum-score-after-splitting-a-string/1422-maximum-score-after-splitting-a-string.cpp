class Solution {
public:
    
    int maxScore(string s) {
        
        int result = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '1'){
                result++;
            }
        }
        
        int answer = 0;
        int zero = 0;
        
        for(int i = 0; i < s.length() - 1; i++){
            if(s[i] == '1'){
                result--;
            }else{
                zero++;
            }
            
            answer = max(answer, result + zero);
        }
        
        return answer;
    }
    
};