class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int currentTotalLeft = 0;
        int currentTotalRight = 0;
        
        int length = nums.size();
        vector<int> leftSum(length);
        vector<int> rightSum(length);
        vector<int> result(length);
        
        for(int i = 0; i < length; i ++){
            leftSum[i] = currentTotalLeft;
            rightSum[length - i - 1] = currentTotalRight;
            
            currentTotalLeft += nums[i];
            currentTotalRight += nums[length-i-1];
        }
        
        for(int i = 0; i < length; i++){
            result[i] = abs(leftSum[i] - rightSum[i]);
        }
        
        return result;
    }
};