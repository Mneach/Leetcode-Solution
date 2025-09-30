/*

How to solve the problem : 

# Using Two Pointer Technique
1. Define left and right pointer (left = 0 and right = 1)
2. if nums[left] == nums[right]
   - multiply nums[left] by 2 and make nums[right] = 0
   - increase left pointer by 1 and increase right pointer by 1
3. if nums[left] != 0 
   - increase left pointer by 1
4. if nums[left] == 0 && nums[right] != 0
   - swap nums[left] with nums[right]
   - increase right pointer by 1

Time Complexity : O(N)
N -> size of nums

Memory Complexity : O(1)

*/

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        int left = 0;
        int right = 1;

        while (right < nums.size()) {
            if (nums[left] == 0 && nums[right] != 0) {
                swap(nums[left], nums[right]);
            }

            if (nums[left] != 0) {
                left++;
            }

            right++;
        }

        return nums;
    }
};