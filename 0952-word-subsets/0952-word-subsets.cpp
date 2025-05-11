class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> answer;
        unordered_map<char,int> ump;
        
        for (auto word : words2) {
            unordered_map<char,int> temp;
            for (int i = 0; i < word.size(); i++) {
                temp[word[i]]++;
            }

            for (auto data : temp) {
                char key = data.first;
                int value = data.second;

                if (ump[key] < value) ump[key] = value;
            }
        }

        for (auto word : words1) {

            unordered_map<char,int> temp;

            for (int i = 0; i < word.size(); i++) {
                temp[word[i]]++;
            }

            bool flag = true;
            for (auto data : ump) {
                char key = data.first;
                int value = data.second;

                if (temp[key] < value) {
                    flag = false;
                    break;
                }
            }

            if (flag) answer.push_back(word);
        }

        return answer;
    }
};