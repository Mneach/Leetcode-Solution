class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        
        int length = nums.size();
        
        for(int j = 0; j < length; j++){
            nums.push_back(nums[j]);        
        }        
        
        
        return nums;
    }
};