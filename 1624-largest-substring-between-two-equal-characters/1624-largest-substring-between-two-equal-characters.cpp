class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        
        
        int answer = -1;
        for(int i = 0; i < s.length() ; i++){
            
            for(int j = s.length() - 1; j > i; j--){
                if(s[i] == s[j]){
                    answer = max(answer, j - i - 1);
                }
            }
        }
        
        return answer;
    }
};