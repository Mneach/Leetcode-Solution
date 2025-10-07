/*

How to solve the problem

# Using sliding window + sorting
1. sort the nums in asc
2. initialize variables
   - left = 0
   - right = 0
   - result = 0
3. while right < nums.size()
   - maximumRangeL = nums[left] + k
   - minimumRangeR = nums[right] - k
   - while minimumRangeR > maximumRangeL
     - increaes the left pointer by 1
     - update the maximumRangeL (maximumRangeL = nums[left] + k)
   - to get the result we can use this formua
     - windowSize = (right - left) + 1
     - result = max(result, windowSize)
   - increase right pointer by 1
4. return the result

Time Complexity : O(N log N + N)
N -> size of nums
N log N -> coming from the sorting algorithm
N -> because we need to loop until right >= nums.size()

Memory Complexity : O(M)
M -> memory that we need to do the merge sort algorithm

*/

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = 0;
        int result = 0;

        while (right < nums.size()) {
            int maximumRangeL = nums[left] + k;
            int minimumRangeR = nums[right] - k;

            while (minimumRangeR > maximumRangeL) {
                left++;
                maximumRangeL = nums[left] + k;
            }

            int windowSize = (right - left) + 1;
            result = max(result, windowSize);
            right++;
        }

        return result;
    }
};