class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {

        int left = 0;
        int total = 1;
        for (int i = 0; i < s.length(); i++) {
            if (i > 0 && s[i] == s[i - 1]) {
                total++;
            } else if (i > 0 && s[i] != s[i - 1]) {
                total = 1;
                left = i - 1;
            }
            if (total == k) {
                if (left > 0 && i < s.length() - 1) {
                    if (s[left] != s[i] && s[i] != s[i + 1]) {
                        return true;
                    } else {
                        left = i;
                    }
                } else if (left == 0 && i < s.length() - 1) {
                   if (s[i] != s[i + 1]) {
                       return true;
                   } 
                } else if (left > 0 && i == s.length() - 1) {
                    if (s[i] != s[left]) {
                        return true;
                    }
                } else if (left == 0 && i == s.length() - 1) {
                    return true;
                }
            }
        }

        return false;
    }
};