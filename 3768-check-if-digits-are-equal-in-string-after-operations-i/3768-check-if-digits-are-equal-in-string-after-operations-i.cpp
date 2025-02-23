class Solution {
public:
    bool hasSameDigits(string s) {
       while(s.length() > 2) {

            string temp = "";

            for (int i = 0; i < s.length() - 1; i++) {
                int first = s[i] - '0';
                int second = s[i + 1] - '0';

                temp += to_string((first + second) % 10);
            }

            s = temp;
       }

       return s[0] == s[1];
    }
};