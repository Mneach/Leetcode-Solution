/*

How to solve the problem : 

# Two Pointer Approach
1. Loop from first index of nums array until last index of nums array
2. count how many same number in array nums, if the same number > 2, change the current number to -1
3. swap nums[left] with nums[right]
3. move the left pointer to the nums[i] that equal to -1

Time Complexity : O(N)
N -> size of nums

Memory Complexity : O(1)

*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        int left = -1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                count++;
            } else {
                count = 1;
            }

            if (count > 2) {
                left = i;
                break;
            }
        }

        if (left == -1) return nums.size();

        int currentNumber = nums[left];
        int currentRight = nums[left];
        int right = left;
        int countRight = 3;

        while(right < nums.size()) {
            if (countRight >= 2) {
                while (right < nums.size() && nums[right] == currentRight) {
                    right++;
                }

                if (right >= nums.size()) break;

                currentRight = nums[right];
                countRight = 0;
            }

            if (currentRight == nums[right]) {
                countRight++;
            } else {
                currentRight = nums[right];
                countRight = 1;
            }

            swap(nums[left], nums[right]);
            left++;
            right++;
        }

        return left;
    }
};