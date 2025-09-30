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
        int left = 0;
        int right = 0;
        
        while (right < nums.size()) {
            if (right < nums.size() - 1 && nums[right] == nums[right + 1]) {
                nums[right] *= 2;
                nums[right + 1] = 0;
            }

            if (nums[right] != 0) {

                if (left != right) {
                    swap(nums[left], nums[right]);
                }

                left++;
            }

            right++;
        }

        return nums;
    }
};