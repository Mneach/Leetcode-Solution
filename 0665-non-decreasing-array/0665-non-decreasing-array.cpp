/*

How to solve the problem

# Using greedy approach
1. Loop from index 1 until the last index of nums
2. if decreasing value happen more than 1 time return false

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