/*

How to solve the problem 

# Using sliding window

Need to split the testcases
1. because if goal == 0, we need to count using different ways

1. if goal == 0
   - count = 0
   - loop from the first number of nums array until last number of nums array
     - if (nusm[i] == 0), then count++
     - else add result by using this formula
       - formula : result += (1LL * count * (count - 1)) / 2
   - if count != 0
     - add result by the formula above
2. else
   - left = 0
   - right = 0
   - count = 0
   - while right < nums.size()
     - decrease goal by nums[right]
     - if goal == 0
       - reset count = 0
       - while goal == 0
         - add goal by nums[left]
         - increaes left pointer by 1
         - increase count by 1
     - add result by count variable

Time Complexity : O(N)
N -> size of nums

Memory Complexity : O(1)


*/


class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int result = 0;

        if (goal == 0) {
            int count = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 0) {
                    count++;
                } else {
                    result += (1LL * count * (count + 1)) / 2;
                    count = 0;
                }
            }
            if (count != 0) {
                result += (1LL * count * (count + 1)) / 2;
            }
        } else {
            int count = 0;
            int left = 0;
            int right = 0;

            while (right < nums.size()) {
                goal -= nums[right];

                if (goal == 0) {
                    // move the left pointer
                    count = 0;
                    while (goal == 0) {
                        goal += nums[left];
                        left++;
                        count++;
                    }

                    result += count;
                } else {
                    result += count;
                }

                right++;
            }
        }

        return result;
    }
};