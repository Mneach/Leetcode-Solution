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

# What makes the algorithm run slowly ? 
1. is because of we need to sort the nums array

# How to improve the algorithm 
1. There is a pattern to solve this problem, we should create nums[i] > nums[i - 1] and nums[i] > nums[i + 1] or nums[i] < nums[i - 1] and nums[i] < nums[i + 1]
   - The reason is because if the neighboar is less than nums[i], that means sum of those neighboar must be less than nums[i] * 2
   - The reason is because if the neighboar is more than nums[i], that means sum of those neightboar must be more than nums[i] * 2

# Greedy 
1. Create a increase flag, by comparing nums[1] with nums[0]
2. If the current flag is increase and nums[i] < nums[i + 1], we need to swap nums[i] with nums[i + 1], so we can create the pattern like this (SLS), then update the flag to decrease. S = small and L = large
3. If the current flag is decrease and nums[i] > nums[i + 1], we neeed to swap nums[i] with nums[i + 1], so we can create the pattern like this (LSL), then update the flag to increase

Time Complexity : O(N)
N -> size of nums

Memory Complexity : O(1)

*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        bool isIncrease = nums[0] < nums[1];

        for (int i = 1; i < nums.size() - 1; i++) {
            
            if (isIncrease && nums[i] < nums[i + 1]) {
                swap(nums[i], nums[i + 1]);
            } else if (!isIncrease && nums[i] > nums[i + 1]) {
                swap(nums[i], nums[i + 1]);
            }

            isIncrease = !isIncrease;
        }

        return nums;
    }
};