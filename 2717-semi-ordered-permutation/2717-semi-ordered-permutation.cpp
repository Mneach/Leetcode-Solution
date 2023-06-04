class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int positionFirst = 0;
        int positionLast = nums.size() - 1;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1) positionFirst = i + 1;
            else if(nums[i] == nums.size()) positionLast = i + 1;
        }
        
        if(positionFirst < positionLast) return positionFirst - 1 + nums.size() - positionLast;
        else return positionFirst - 1 + nums.size() - positionLast - 1;
    }
};