class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int leftSum = 0;
        int rightSum = 0;
        
        int length = nums.size();
        vector<int> answer;
        
        for(int i = 0; i < length; i ++){
            rightSum += nums[i];
        }
        
        for(int i = 0; i < length; i++){
            rightSum -= nums[i];
            answer.push_back(abs(leftSum - rightSum));
            leftSum += nums[i];
        }
        
        return answer;
    }
};