class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int currentSum = 0;
        
        vector<int> answer;
        
        for(int i = 0; i < nums.size(); i++){
            
            currentSum += nums[i];
            
            answer.push_back(currentSum);
        }
        
        return answer;
    }
};