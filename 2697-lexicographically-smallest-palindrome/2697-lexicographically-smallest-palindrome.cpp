class Solution {
public:
    string makeSmallestPalindrome(string s) {
        
        for(int i = 0; i < s.length() / 2; i++){
            char x = s[i];
            char y = s[s.length() - i - 1];
            
            if(x != y){
                if(x > y) s[i] = y;
                else s[s.length() - i - 1] = x;
            }
        }
        
        return s;
    }
};