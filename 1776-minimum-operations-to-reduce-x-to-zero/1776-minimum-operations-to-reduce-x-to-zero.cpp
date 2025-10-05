/*

How to solve the problem :

# Using sliding window

Idea : 
1. instead of find the total numbers from nums array that equal to x based on the condition that given from the problem description, it is better to find the subarray that we need to eliminate, so the rest of the numbers in array nums can be equal to the x, formula : 
   - a = x + z
   - a = total all of the numbers in array nums
   - x = value given from the problem description
   - z = ? 
   - z = a - x 
2. so we just need to find the z value using sliding window

Steps : 
1. initialize variables
   - left = 0
   - right = 0
   - sum = 0
   - target = 0
   - result = INT_MAX
2. get the total target using this formula
   - total of number in array nums - x
3. while left <= right && sum > target
   - decrease sum by nums[left]
   - increase left pointer by 1
4. if sum == target
   - get the result (result = min(result, (right - left) + 1))

Time Complexity : O(N + N)
N -> size of nums

Memory Complexity : O(1)

*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int left = 0;
        int right = 0;
        long long sum = 0;
        long long target = 0;
        int result = INT_MAX;
        int size = nums.size();

        for (auto number : nums) {
            target += number;
        }

        target -= x;

        while (right < size) {
            sum += nums[right];

            while (left <= right && sum > target) {
                sum -= nums[left];
                left++;
            }

            if (sum == target) {
                result = min(result, size - ((right - left) + 1));
            }

            right++;
        }

        if (result == INT_MAX) {
            return -1;
        }

        return result;
    }
};