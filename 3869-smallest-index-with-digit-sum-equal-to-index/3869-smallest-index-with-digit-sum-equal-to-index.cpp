class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];

            int totalDigit = 0;

            while (num > 0) {
                totalDigit += num % 10;
                num /= 10;
            }

            if (totalDigit == i) return i;
        }
        
        return -1;
    }
};