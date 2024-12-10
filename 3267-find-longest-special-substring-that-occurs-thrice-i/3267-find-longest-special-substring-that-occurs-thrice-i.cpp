class Solution {
public:
    int maximumLength(string s) {
        int answer = -1;
        unordered_map<char,vector<int>> ump;
        

        for (int i = 0; i < s.length(); i++){
            ump[s[i]].push_back(i);
        }

        for (auto data : ump) {
            char x = data.first;

            // cout << x << " " << data.second.size() << endl;

            int temp = 1;
            bool valid = true;

            while (valid) {
                int left = data.second[0];
                int totalValid = 0;
                for (int i = 0; i < data.second.size(); i++) {

                    // need to reset the left pointer, becuase we cant create the substring
                    if (i > 0 && data.second[i - 1] + 1 != data.second[i]) {
                        left = data.second[i];
                    }

                    int index = data.second[i];
                    int windowLength = (index - left) + 1;

                    // cout << index << " " << left << " " << windowLength << endl;

                    if (windowLength == temp) {
                        totalValid++;
                        left++;
                    }

                    if (totalValid == 3) break;
                }

                // cout << temp << " " << totalValid << endl;

                if (totalValid < 3) {
                    valid = false;
                } else {
                    answer = max(answer, temp);
                }

                temp++;
            }

            if (valid) answer = max(answer, temp);
        }

        return answer;
    }
};