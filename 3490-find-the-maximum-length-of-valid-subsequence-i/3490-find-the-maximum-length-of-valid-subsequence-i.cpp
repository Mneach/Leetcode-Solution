class Solution {
public:
    int maximumLength(vector<int>& nums) {
        
        int totalOdd = 0;
        int totalEven = 0;
        int totalEvenOdd = 0;
        int totalOddEven = 0;

        int countOdd = 1;
        int countEven = 0;
        
        for(int i = 0; i < nums.size(); i++){
            int number = nums[i];
            
            if(number % 2 == 0) {
                totalEven++;
            }else if(number % 2 == 1){
                totalOdd++;
            }
            
            if(number % 2 == 0 && countEven % 2 == 0){
                // take even odd with even number
                totalEvenOdd++;
                countEven++;
            }else if(number % 2 == 1 && countEven % 2 == 1){
                // take even odd with odd number
                totalEvenOdd++;
                countEven++;
            }
            
            if(number % 2 == 1 && countOdd % 2 == 1){
                // take odd even with odd number
                totalOddEven++;
                countOdd++;
            }else if(number % 2 == 0 && countOdd % 2 == 0){
                // take odd even with even number
                totalOddEven++;
                countOdd++;
            }
            
            // cout << totalOdd << " " << totalEven << " " << totalEvenOdd << " " << totalOddEven << endl;
        }
        
        return max(totalOdd, max(totalEven, max(totalEvenOdd, totalOddEven)));
    }
};