class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int totalOne = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '1') totalOne++;
        }
        
        string answer = s;
        
        for(int i = 0; i < s.length(); i++){
            if(totalOne == 1 && i == s.length() - 1){
                answer[i] = '1';
            }else if(totalOne > 1){
                answer[i] = '1';
                totalOne--;
            }else{
                answer[i] = '0';
            }
        }
        
        return answer;
    }
};