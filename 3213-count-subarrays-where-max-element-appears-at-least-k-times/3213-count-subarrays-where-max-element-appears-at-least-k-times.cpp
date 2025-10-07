/*

How to solve the problem 

1. initialize variables
   - left = 0
   - right = 0
   - result = 0
   - maximumNumber = 0
   - count = 0
   - currentValidSubarray = 0
2. find the maximum number in array nums
3. while right < nums.size()
   - if (nums[right] == maximumNumber)
     - add count by 1
   - if (count >= k)
     - while (count >= k)
       - increase currentValidSubArray by 1
       - if (nums[left] == maximumNumber)
         - decrease the count by 1
   - get the result using this formula
     - formula : result += currentValidSubarray
   - increaes right pointer by 1
4. return the result

Time Complexity : O(N + N + N) = O(N)
N -> size of nums
first N -> because we need to find the maximum number in nums array
second N -> because we need to loop right pointer until nums.size()
third N -> because we need to move the left pointer

Memory Compelxity : O(1)

*/


class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        long long count = 0;
        long long result = 0;
        long long currentValidSubArray = 0;
        int maximumNumber = *max_element(nums.begin(), nums.end());

        while (right < nums.size()) {
            if (nums[right] == maximumNumber) {
                count++;
            }

            if (count == k) {
                while (count == k) {
                    currentValidSubArray++;
                    if (nums[left] == maximumNumber) {
                        count--;
                    }
                    left++;
                }
            }

            result += currentValidSubArray;
            right++;
        }

        return result;
    }
};