/*

How to solve the problem : 
1. Loop for every word in words, and find if the current word is the substring of the another word
2. to find the current word is the substring of the another word, we can use these steps
   2.1 compare if currentWord[i] == anotherWord[j]
   2.1.1 if it is equal, then increase the index i and j
   2.2.1 if it is not euqal, reset the index i = 0 and we will move into another word

Time Complexity : O(N ^ 2 * M)
N -> length of words array
M -> length of word string

Memory complexity : O(1)

*/

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> answer;
        for (int i = 0; i < words.size(); i++) {
            string current = words[i];

            for (int j = 0; j < words.size(); j++) {
                if (i == j) continue;

                string anotherWord = words[j];

                bool valid = false;                
                int indexCurrent = 0;

                for (int k = 0; k < anotherWord.length(); k++) {

                    int temp = k;

                    while (
                        indexCurrent < current.length() && 
                        temp < anotherWord.length() && 
                        current[indexCurrent] == anotherWord[temp]
                        ) {
                        indexCurrent++;
                        temp++;
                    }

                    if (indexCurrent == current.length()) {
                        valid = true;
                        break;
                    } else {
                        indexCurrent = 0;
                    }
                }

                if (valid) {
                    answer.push_back(current);
                    break;
                }
            }
        }

        return answer;
    }
};