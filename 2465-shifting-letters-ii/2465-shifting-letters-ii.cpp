class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> bucket(s.length(), 0);        

        for (auto shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];

            if (direction == 1) {
                bucket[start]++;

                if (end + 1 < s.length()) {
                    bucket[end + 1]--;
                }
            } else {
                bucket[start]--;

                if (end + 1 < s.length()) {
                    bucket[end + 1]++;
                }
            }
        }

        int totalShift = 0;

        for (int i = 0; i < s.length(); i++) {
            totalShift += bucket[i] % 26;

            if (totalShift < 0) {
                // need to reverse 
                totalShift += 26;
            }

            int ascii = s[i] - 'a';
            s[i] = ((ascii + totalShift) % 26) + 'a';
        }

        return s;
    }
};