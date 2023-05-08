class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;

        unordered_map<int, int> umap;

        for(int i = 0; i < nums.size(); i++){
            int substract = target - nums[i];
            if(umap.count(substract) > 0){    
                return {umap[substract] , i};
            }else{
                umap[nums[i]] = i;
            }
        }

        return answer;
    }
};