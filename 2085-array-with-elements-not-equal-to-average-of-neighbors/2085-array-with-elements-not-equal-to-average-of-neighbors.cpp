/*

How to solve the problem :

# Using Two Pointer Technique
1. sort the nums in asc order
2. loop from first index until nums / 2
3. initialize two pointer
4. left = 0 and right = nums.size() - 1
5. push nums[right] and nums[left] to the answer array

edge cases : 
1. what if nums.size() is odd ? 
   - we just need to push nums[left] or nums[right] to the answer

Time Complexity : O(N log N + N / 2)
N -> size of nums
N log N -> come from sort algorithm
N / 2 -> to get the answer

Memory Complextiy : O(M)
M -> size of answers array

*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> answers(nums.size(), 0);

        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        int index = 0;

        while (left <= right) {
            if (left != right) {
                answers[index] = nums[right];
                answers[index + 1] = nums[left];
                index += 2;
            } else {
                answers[index] = nums[left];
            }
            left++;
            right--;
        }

        return answers;
    }
};