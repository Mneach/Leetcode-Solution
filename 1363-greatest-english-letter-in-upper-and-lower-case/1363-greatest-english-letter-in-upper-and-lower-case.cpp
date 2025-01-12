class Solution {
public:
    string greatestLetter(string s) {
        vector<int> lowerCharacters(26, 0);
        vector<int> upperCharacters(26, 0);

        for (auto c : s) {
            if (c >= 'a' && c <= 'z') {
                lowerCharacters[c - 'a']++;
            } else if (c >= 'A' && c <= 'Z') {
                upperCharacters[c - 'A']++;
            }
        }

        int maxIndex = -1;
        for (int i = 0; i < 26; i++){
            if (lowerCharacters[i] > 0 && upperCharacters[i] > 0) {
                maxIndex = i;
            }
        }

        if (maxIndex == -1) return "";

        char c = maxIndex + 'A';
        string answer = "";

        return answer + c;
    }
};