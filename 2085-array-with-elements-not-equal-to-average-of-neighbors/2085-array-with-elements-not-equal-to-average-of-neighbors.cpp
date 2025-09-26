/*

How to solve the problem :

# Using Two Pointer Technique
1. sort the nums in asc order
2. loop from first index until nums / 2
3. initialize two pointer
4. left = 0 and right = nums.size() - 1
5. push nums[right] and nums[left] to the answer array

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
        vector<int> answers;

        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            if (left != right) {
                answers.push_back(nums[right]);
                answers.push_back(nums[left]);
            } else {
                answers.push_back(nums[left]);
            }
            left++;
            right--;
        }

        return answers;
    }
};