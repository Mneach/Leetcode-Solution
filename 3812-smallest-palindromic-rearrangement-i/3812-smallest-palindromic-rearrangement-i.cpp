class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> bucket(26, 0);

        for (auto c : s) {
            int ascii = c - 'a';
            bucket[ascii]++;
        }

        int totalOdd = 0;
        int currentIndex = 0;
        char oddChar = ' ';

        for (int i = 0; i < 26; i++) {
            if (bucket[i] > 0 && bucket[i] % 2 == 1) {
                int current = 0;

                while (current < bucket[i] - 1) {
                    s[currentIndex] = i + 'a';
                    s[s.length() - currentIndex - 1] = i + 'a';
                    current += 2;
                    currentIndex++;
                }
                
                // fill the mid
                s[s.length() / 2] = i + 'a';
            } else if (bucket[i] > 0 && bucket[i] % 2 == 0) {
                int current = 0;
                while (current < bucket[i]) {
                    s[currentIndex] = i + 'a';
                    s[s.length() - currentIndex - 1] = i + 'a';
                    current += 2;
                    currentIndex++;
                }
            }
        }
        
        return s;
    }
};