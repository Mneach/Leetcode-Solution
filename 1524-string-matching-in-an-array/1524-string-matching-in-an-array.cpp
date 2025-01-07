class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> answer;
        
        for (int i = 0; i < words.size(); i++) {

            string find = words[i];
            for (int j = 0; j < words.size(); j++) {

                if (i == j) continue;
                
                if(words[j].find(find) != string::npos){
                    answer.push_back(find);
                    break;
                }
            }
        }

        return answer;
    }
};