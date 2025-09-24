/*

How to solve the problem : 

# Using Two Pointer Technique
1. Initialize left and right pointer
2. left = 0, right = 0
3. looping until right >= nums.size()
4. if nums[right] != 0
   - move left pointer to nums[left] == 0, and make sure left < right
   - if nums[left] == 0, swam nums[left] to nums[right]
5. increase right pointer by 1

Time Copmlexity : O(N)
N -> size of nums

Memory Compelixty : O(1)


*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        int right = 0;

        while (right < nums.size()) {
            if (nums[right] != 0) {
                while(left < right && nums[left] != 0) {
                    left++;
                }

                if (nums[left] == 0) {
                    swap(nums[left], nums[right]);
                    left++;
                }
            }
            right++;
        }
    }
};