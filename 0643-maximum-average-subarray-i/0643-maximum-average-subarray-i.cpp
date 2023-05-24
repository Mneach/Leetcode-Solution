class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double answer = 0;
        
        for(int i = 0; i < k; i++) answer += nums[i];
        
        double curr = answer;
        for(int i = k ; i < nums.size(); i++){
            curr += nums[i] - nums[i - k];
            
            answer = max(curr , answer);
        }
        
        return answer / k;
    }
};