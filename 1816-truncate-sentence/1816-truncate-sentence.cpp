class Solution {
public:
    string truncateSentence(string s, int k) {
        
        
        string answer = "";
        
        
        int end = s.length();
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' ') k--;
            
            if(k == 0){
                end = i;
                break;
            }
        }
        
        answer = s.substr(0, end);
        
        return answer;
    }
};