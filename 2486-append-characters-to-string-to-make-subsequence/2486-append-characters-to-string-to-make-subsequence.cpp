class Solution {
public:
    int appendCharacters(string s, string t) {
        
        int currIndex = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == t[currIndex]) currIndex++;
        }
        
        return t.length() - currIndex;
    }
};