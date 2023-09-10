class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        
        set<int> arr;
        for(int i = 0; i < nums.size(); i++){
            for(int j = nums[i][0]; j <= nums[i][nums[i].size() - 1]; j++){
                arr.insert(j);
            }
        }   
        
        return arr.size();
    }
};