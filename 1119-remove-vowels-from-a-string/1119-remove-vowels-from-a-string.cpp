class Solution {
public:
    string removeVowels(string s) {
        
        string answer = "";
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u'){
                answer += s[i];
            }
        }
        
        return answer;
    }
};