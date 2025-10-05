/*

How to solve the problem 

# Using Sliding Window + Sorting
1. sort nums in asc
2. initialize left, right, and result (left = 0, right = 0, and result = INT_MAX)
3. while right < nums.size()
   - if ((right - left) + 1 == k)
     - take the lowest number (nums[left])
     - take the higest number (nums[right])
     - get the different between lowest and highest (result = min(result, nums[right] - nums[right]))
     - increase the left pointer
   - increase the right pointer
4. return the result

Time Complexity : O(N log N + N)
N -> size of nums

Memory Complexity : O(N)
N -> size of nums

*/


class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int result = INT_MAX;

        sort(nums.begin(), nums.end());

        while (right < nums.size()) {
            if ((right - left) + 1 == k) {
                result = min(result, nums[right] - nums[left]);
                left++;
            }

            right++;
        }

        return result;
    }
};