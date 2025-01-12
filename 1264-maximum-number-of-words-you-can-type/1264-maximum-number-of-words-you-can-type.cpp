class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char,int> ump;       

        for (auto c : brokenLetters) {
            ump[c]++;
        }

        int answer = 0;
        bool valid = true;
        for (auto c : text) {
            if (c == ' ') {
                // need to reset the state

                if (valid == true) answer++;

                valid = true;
            } else if (ump[c] > 0) {
                valid = false;
            }
        }

        if (valid) answer++;

        return answer;
    }
};