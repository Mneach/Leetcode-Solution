class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double answer = -100000;
        
        double tempAnswer = 0;
        double currentAddition = 0;
        for(int i = 0 ; i < nums.size(); i++){
            tempAnswer += nums[i];
            if((i + 1) >= k){
                answer = max(answer , (double) tempAnswer / k);   
                tempAnswer -= nums[currentAddition];               
                currentAddition++;
            }
        }
        
        return answer;
    }
};