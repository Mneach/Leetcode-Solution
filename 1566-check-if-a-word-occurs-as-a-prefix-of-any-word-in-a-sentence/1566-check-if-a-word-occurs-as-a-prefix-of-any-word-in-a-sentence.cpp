class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int current = 1;
        bool find = true;
        int indexFind = 0;

        for (int i = 0; i < sentence.size(); i++) {
            if (find == true) {
                if(searchWord[indexFind] == sentence[i]) {
                    indexFind++;
                } else {
                    indexFind = 0;
                    find = false;
                }

                if(indexFind == searchWord.size()) {
                    return current;
                }
            }

            if (i == 0 && sentence[i] == searchWord[i]) {
                find = true;
            }

            if (sentence[i] == ' ') {
                current++;
                find = true;
                indexFind = 0;
            }
        }

        return -1;
    }
};