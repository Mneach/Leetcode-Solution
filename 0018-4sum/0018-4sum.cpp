/*

How to solve the problem 

# Using two pointer technique
1. sort the nums asc
2. Loop for every number in nums array
   - skip the duplicate number
   - pick one number, then decrease the target by that number
   - loop again from j = i + 1 until nums.size() - 1
     - skip the duplicate number
     - pick one number, then decresase the target by that number
     - do two pointer where left = j + 1 and right = nums.size() - 1 
       - skip the duplicate number
       - if the current sum > target, move the right pointer by 1
       - else if the current sum < target, move the left pointer by 1
       - else
         - put those numbers to the answer
         - move left pointer by 1

Time Complexity : O(N log N + N^3)
N -> size of nums

Memory Complexity : O(1)

*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> answers;

        sort(nums.begin(), nums.end());

        long long temp = target;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int a = nums[i];
            temp -= a;

            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                int b = nums[j];
                temp -= nums[j];

                // two pointer technique
                int left = j + 1;
                int right = nums.size() - 1;

                while (left < right) {
                    if (left > j + 1 && nums[left] == nums[left - 1]) {
                        left++;
                        continue;
                    }

                    long long sum = nums[left] + nums[right];

                    if (sum > temp) {
                        right--;
                    } else if (sum < temp) {
                        left++;
                    } else {
                        answers.push_back({a, b, nums[left], nums[right]});
                        left++;
                    }
                }

                temp += nums[j];
            }

            temp += nums[i];
        }

        return answers;
    }
};