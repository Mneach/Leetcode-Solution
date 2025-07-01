class Solution {
public:
    void sortColors(vector<int>& nums) {

        int one = 0; 
        int zero = 0;
        for (int two = 0; two < nums.size(); two++) {

            int temp = nums[two];
            nums[two] = 2;

            if (temp < 2) {
                nums[one] = 1;
                one++;
            }

            if (temp < 1) {
                nums[zero] = 0;
                zero++;
            }
        }
    }
};