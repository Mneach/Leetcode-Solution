class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        
        set<pair<int,int>> bucket;
        vector<int> answer(k, 0);
        
        for(auto data : logs){
            pair<int,int> currentData = make_pair(data[0], data[1]);
            bucket.insert(currentData);
        }
        
        unordered_map<int,int> totalMinutes;
        for(auto data : bucket){
            totalMinutes[data.first]++;
        }
        
        for(auto data : totalMinutes){
            answer[data.second - 1]++;
        }
        
        return answer;
    }
};