class Solution {
public:
    string freqAlphabets(string s) {
        string decoded;
        int i = 0, n = s.length();

        while (i < n) {
            if (i + 2 < n && s[i + 2] == '#') {
                // Handle two-digit codes (10-26) represented with '#'
                int charCode = (s[i] - '0') * 10 + (s[i + 1] - '0');
                decoded += 'a' + charCode - 1;
                i += 3;
            } else {
                // Handle single-digit codes (1-9)
                decoded += 'a' + (s[i] - '0') - 1;
                i++;
            }
        }

        return decoded;
    }
};