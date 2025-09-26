/*

How to solve the problem 

# Using Two Pointer Technique
1. Initialize left and right pointer (left = 0 and right = 0)
2. while right < nums.size()
   - while left < right && nums[left] % 2 == 0
     - increase left pointer by 1
   - if (nums[left] % 2 == 1 && nums[right] % 2 == 1) 
     - swap nums[left] with nums[right]

Time Complexity : O(N)
N -> size of nums

Memory Complexity : O(1)

*/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0;
        int right = 0;

        while (right < nums.size()) {

            while (left < right && nums[left] % 2 == 0) {
                left++;
            } 

            if (nums[left] % 2 == 1 && nums[right] % 2 == 0) {
                swap(nums[left], nums[right]);
            }

            right++;
        }

        return nums;
    }
};
