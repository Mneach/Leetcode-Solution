class Solution {
public:
    int maxVowels(string s, int k) {
        int answer = 0;
        
        int currentTotalVowels = 0;
        for(int i = 0; i <= s.length(); i++){
            
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ){
                currentTotalVowels++;
            }
            
            if(i >= k){
                if(s[i - k] == 'a' || s[i - k] == 'e' || s[i - k] == 'i' || s[i - k] == 'o' || s[i - k] == 'u' ){
                    currentTotalVowels--;
                }
            }
           
             answer = max(currentTotalVowels, answer);
        }
        
        return answer;
    }
};