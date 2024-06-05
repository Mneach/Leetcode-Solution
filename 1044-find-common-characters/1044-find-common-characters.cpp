class Solution {
public:

    vector<string> commonChars(vector<string>& words) {
        vector<vector<int>> bucket(words.size(), vector<int>(26, 0));
        vector<string> answer;

        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].length(); j++){
                int x = words[i][j] - 'a';

                bucket[i][x]++;
            }
        }

        // for(int i = 0; i < 26; i++){
        //     cout << char(i + 'a') << " ";
        //     for(int j = 0; j < words.size(); j++){
        //         cout << bucket[j][i] << " ";
        //     }

        //     cout << endl;
        // }


        for(int i = 0; i < 26; i++){
            bool check = false;
            int total = INT_MAX;

            // cout << char(i + 'a') << " ";
            for(int j = 0; j < words.size() - 1; j++){
                // cout << bucket[j][i] << " ";
                if(bucket[j][i] > 0 && bucket[j + 1][i] > 0){
                    check = true;
                    total = min(total, bucket[j][i]);

                    if(j + 1 == words.size() - 1){
                        total = min(total, bucket[j + 1][i]);
                    }
                }else{
                    check = false;
                    break;
                }
            }

            if(check){
                // cout << "total = " << total << " " ;
                while(total > 0){
                    char x = i + 'a';
                    string temp = "";
                    temp += x;
                    answer.push_back(temp);
                    total--;
                }
            }

            // cout << endl;
        }

        return answer;
    }
};