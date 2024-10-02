class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> mp;

        for(auto data : arr){
            mp[data]++;
        }
        unordered_map<int,int> ump;

        int rank = 1;
        for(auto data : mp){
            ump[data.first] = rank;
            rank++;
        }

        vector<int> answer;
        
        for(auto data : arr){
            answer.push_back(ump[data]);
        }

        return answer;
    }
};