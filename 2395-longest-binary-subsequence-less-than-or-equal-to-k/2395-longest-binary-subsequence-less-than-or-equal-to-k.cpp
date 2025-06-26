class Solution {
public:
    int longestSubsequence(string s, int k) {
        int val = 0;
        int totalOne = 0;
        int totalZero = 0;
        int pow = 1;

        for (int i = s.length() - 1; i >= 0 && val + pow <= k; i--) {
            if (s[i] == '1') {
                totalOne++;
                val += pow;
            }

            pow *= 2;
        }

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                totalZero++;
            }
        }

        return totalOne + totalZero;
    }
};