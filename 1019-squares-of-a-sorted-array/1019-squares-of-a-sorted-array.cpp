/*

How to solve the problem : 

# Using sorting
1. Change all of number in nums array to sqrt
2. Sort the array

Time Complexity : O(N + N log N)
N -> size of nums

Memory Complexity : O(1)

# Using Two Pointer 
1. Initialize left and right pointer
2. left = 0 and right = nums.size() - 1;
3. compare nums[i] ^ 2 with nums[right] ^ 2, put the highest value at end index of answer array
4. if nums[i]^2 > nums[right]^2, then increase the left pointer
5. else decrease the right pointer

Time Complexity : O(N)
N -> size of nums

Memory Complexity : O(N)
N -> size of nums

*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> answers(nums.size(), 0);
        int left = 0;
        int right = nums.size() - 1;
        int answerIndex = nums.size() - 1;

        while (left <= right) {
            long long leftResult = nums[left] * 1LL * nums[left];
            long long rightResult = nums[right] * 1LL * nums[right];

            if (leftResult > rightResult) {
                answers[answerIndex] = leftResult;
                left++;
            } else {
                answers[answerIndex] = rightResult;
                right--;
            }

            answerIndex--;
        }

        return answers;
    }
};