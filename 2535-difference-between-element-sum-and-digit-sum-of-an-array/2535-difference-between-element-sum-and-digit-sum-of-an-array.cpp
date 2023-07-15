class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        
        int totalNumber = 0;
        int totalDigit = 0;
        
        for(int i = 0; i < nums.size(); i++){
            totalNumber += nums[i];
            
            int temp = nums[i];
            while(temp > 0){
                totalDigit += temp % 10;
                temp /= 10;
            }
        }
        
        return abs(totalNumber - totalDigit);
    }
};