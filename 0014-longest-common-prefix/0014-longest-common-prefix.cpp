class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string answer = "";
        string first = strs[0];

        for (int i = 0; i < first.length(); i++) {
            char currentWord = first[i];
            bool valid = true;
            
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].length()) {
                    valid = false;
                    break;
                }

                char word = strs[j][i];
                if (currentWord != word) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                answer += currentWord;
            } else {
                break;
            }
        }

        return answer;
    }
};