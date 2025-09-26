/*

How to solve the problem

# Using two pointer approach
1. initialize two pointer (odd and even pointer)
2. even = 1 and odd = 0
3. create answers array with size = nums.size()
4. loop from first index of nums array until last index of nums array
   - if nums[i] is positive
     - put nums[i] in answers[positiveIndex]
     - increase positiveIndex index by 2
   - if nums[i] is negative
     - put nums[i] in answers[negativeIndex]
     - increase negativeIndex index by 2

Time Complexity : O(N)
N -> size of nums

Memory Complexity : O(n)
N -> size of nums

*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> answers(nums.size(), 0);
        int negativeIndex = 1;
        int positiveIndex = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                answers[negativeIndex] = nums[i];
                negativeIndex += 2;
            } else {
                answers[positiveIndex] = nums[i];
                positiveIndex += 2;
            }
        }

        return answers;
    }
};