class Solution {
public:
    int balancedStringSplit(string s) {
        
        int totalL = 0;
        int totalR = 0;
        
        int answer = 0;
        for(int i = 0; i < s.length(); i++){
            
            if(s[i] == 'L') totalL++;
            else if(s[i] == 'R') totalR++;
            
            if(totalL == totalR){
                answer++;
                totalL = 0;
                totalR = 0;
            } 
        }
        
        return answer;
    }
};