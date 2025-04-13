class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> bucket(26, 0);

        for (auto c : s) {
            int ascii = c - 'a';
            bucket[ascii]++;
        }

        int currentIndex = 0;

        for (int i = 0; i < 26; i++) {
            if (bucket[i] > 0) {
                int current = 0;
                int total = bucket[i] % 2 == 1 ? bucket[i] - 1 : bucket[i];

                while(current < total) {
                    s[currentIndex] = i + 'a';
                    s[s.length() - currentIndex - 1] = i + 'a';
                    current += 2;
                    currentIndex++;
                }

                if (bucket[i] % 2 == 1) {
                    s[s.length() / 2] = i + 'a';
                }
            }
        }
        
        return s;
    }
};