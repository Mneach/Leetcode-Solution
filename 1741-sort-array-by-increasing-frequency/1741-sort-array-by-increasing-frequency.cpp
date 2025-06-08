class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> ump;

        for(auto data : nums) ump[data]++;

        vector<pair<int,int>> vp;

        for(auto data : ump){
            vp.push_back(make_pair(data.first, data.second));
        }

        sort(vp.begin(), vp.end(), [](pair<int,int> &p1, pair<int,int> &p2){
            if(p1.second == p2.second){
                return p1.first > p2.first;
            }else{
                return p1.second < p2.second;
            }
        });

        vector<int> answer;

        for(auto data : vp){
            for(int i = 0; i < data.second; i++){
                answer.push_back(data.first);
            }
        }

        return answer;
    }
};