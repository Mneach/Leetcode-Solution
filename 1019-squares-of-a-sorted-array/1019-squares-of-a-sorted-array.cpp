/*

How to solve the problem : 

# Using sorting
1. Change all of number in nums array to sqrt
2. Sort the array

Time Complexity : O(N + N log N)
N -> size of nums

Memory Complexity : O(1)

*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] *= nums[i];
        }

        sort(nums.begin(), nums.end());

        return nums;
    }
};