class Solution {
public:
    bool isSubsequence(string s, string t) {
        int currentIndex = 0;
        
        for(int i = 0; i < t.length(); i++){
            if(s[currentIndex] == t[i]) currentIndex++;
        }
        
        return s.length() == currentIndex;
    }
};