class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        map<long long,long long> bucket;
        
        for(int i = 0; i < nums.size(); i++){
            bucket[nums[i]]++;
        }
        
        for(int i = 0; i < moveFrom.size(); i++){
            if(bucket[moveTo[i]]) bucket[moveTo[i]] += bucket[moveFrom[i]];
            else bucket[moveTo[i]] = bucket[moveFrom[i]];
            
            if(moveTo[i] != moveFrom[i]) bucket[moveFrom[i]] = 0;
        }
        
        vector<int> answer;
        
        for(auto x : bucket){
            if(x.second != 0) answer.push_back(x.first);
        }
        
        return answer;
    }
};