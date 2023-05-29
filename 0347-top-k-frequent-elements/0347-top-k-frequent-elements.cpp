class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int , int> map;
        
        for(int i = 0; i < nums.size(); i++){
            if(map[nums[i]]){
                map[nums[i]]++;
            }else{
                map[nums[i]] = 1;
            }
        }
        
        vector<vector<int>> bucket(nums.size() + 1);
        for(auto x : map){
            bucket[x.second].push_back(x.first);
        }
        
        vector<int> answer;
        for(int i = bucket.size() - 1; i >= 0; i--){
            for(int j = 0; j < bucket[i].size(); j++){
                
                answer.push_back(bucket[i][j]);
                
                if(answer.size() == k) return answer;
            }
        }
        
        return answer;
    }
                  
};