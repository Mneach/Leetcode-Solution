class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> answer;
        map<int,vector<int>> mp;

        for(int i = 0; i < nums.size(); i++){
            int number = nums[i];
            string temp = to_string(number);

            string res = "";
            for(int j = 0; j < temp.size(); j++){
                res += to_string(mapping[temp[j] - '0']);
            }

            // cout << res << endl;

            mp[stoi(res)].push_back(number);
        }

        for(auto data : mp){

            for(int i = 0; i < data.second.size(); i++){
                answer.push_back(data.second[i]);
            }
        }

        return answer;
    }
};