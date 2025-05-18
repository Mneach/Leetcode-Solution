class Solution {
public:

    bool isVowel(char x) {
        return (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u');
    }

    int maxFreqSum(string s) {
        int totalVowel = 0;
        int totalConsonant = 0;
        vector<int> bucket(27, 0);

        for (auto c : s) {
            bucket[c - 'a']++;
        }

        for (int i = 0; i < bucket.size(); i++) {
            char x = i + 'a';
            if (isVowel(x)) {
                totalVowel = max(totalVowel, bucket[i]);
            } else {
                totalConsonant = max(totalConsonant, bucket[i]);
            }
        }

        return totalVowel + totalConsonant;
    }
};