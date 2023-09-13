class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        
        for(int i = 0; i < s1.length(); i++){
            
            int indexNext = (i + 2) % s1.length();
            
            if(s1[i] == s2[i] && s1[indexNext] == s2[indexNext]) continue;
            if(s1[i] != s2[indexNext] || s1[indexNext] != s2[i]){
                return false;
            }
        }
        
        return true;
    }
};