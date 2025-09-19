/*

How to solve the problem

# Using greedy approach
1. Loop from index 1 until the last index of nums
2. if we meet decreasing value, then there will be 2 possibility, either update the current value to become the previous value (nums[i] = nums[i - 1]) or update the prev value to become the first value
   - if it is happen for the first time, we need to check what if we change the previous value to become the current value 
     - loop from the previous index until index 1 to make sure the array is valid after we change nums[i - 1] to become nums[i]
     - if it is valid, then the next time we meet decreasing value, we should return false. Because we only have 1 opportunity to change the number
     - if it is not valid, then we need to change the current value to become the previous value, then the next time we meet decreasing value, we should return false

Time Complexity : O(N)
N -> total number in nums array

Memory Complextiy : O(1)

*/


class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int total = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                int current = nums[i];
                int prev = nums[i - 1];

                bool valid = true;
                nums[i - 1] = current;

                for (int j = i - 1; j >= 1; j--) {
                    if (nums[j] < nums[j - 1]) {
                        valid = false;
                        break;
                    }
                }

                if (valid == false && total == 0) {
                    nums[i] = prev;
                }

                total++;
            }

            if (total == 2) {
                return false;
            }
        }

        return true;
    }
};