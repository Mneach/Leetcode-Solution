/*

How to solve the problem : 

# Two Pointer Technique Approach
1. every time we meet number 1 in nums of array, we will increaes the count variable by 1
2. every time we meet number 0 in nums of array, we reset the count and calculate the answer by using this formula answer = max(answer, count)

edge cases : 
1. what if all the numbers in the nums of array is equal to 1 ? 
   - if that the case we just need to recheck the answer using this formula after loop process
   - formula : answer = max(answer, count)

Time complexity : O(N)
N -> size of nums array

Memory complexity : O(1)

*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int answer = 0;
        int count = 0;

        for (auto number : nums) {
            if (number == 0) {
                answer = max(answer, count);
                count = 0;
            } else {
                count++;
            }
        }

        answer = max(answer, count);

        return answer;
    }
};