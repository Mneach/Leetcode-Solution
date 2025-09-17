/*

How to solve the problem : 

# Native Approach 
1. loop from first index of nums array until last index of nums array
   - if nums[i] <= nums[i + 1], calculate the sum of increasing sub array, if the sum > current answer, then update the current ansewr
   - else if (nums[i] > nums[i + 1]), update the sum value

edge cases : 
1. what if all the number in nums array are increasing ? 
   - outside the loop we need to update the answer value

Time Complexity : O(N)
N -> size of nums array

Memory Complexity : O(1)

*/

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int answer = nums[0];
        int sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                answer = max(answer, sum);
                sum = nums[i];
            } else {
                sum += nums[i];
            }
        }

        answer = max(answer, sum);

        return answer;
    }
};