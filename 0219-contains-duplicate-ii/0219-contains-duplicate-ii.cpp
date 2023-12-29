class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        
        map<int, vector<int>> mp;
        
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]].push_back(i);
        }
        
        for(auto data : mp){
            vector<int> indexs = data.second;
            
            for(int i = 0; i < indexs.size() - 1; i++){
                if(abs(indexs[i] - indexs[i + 1]) <= k){
                    return true;
                }
            }
        }
        
        return false;
    }
};