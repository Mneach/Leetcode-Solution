/*

How to solve the problem : 

# Brute Force Solution
1. Create all combinations of sub arrays
2. left sub array must have nums[0] until nums[i]
3. right sub array must have nums[i + 1] until nums[nums.size() - 1]
4. sum left sub array and sum right sub array, after that compare left with right sub array, if sum of left sub array >= sum of right sub array, then increase the answer value by 1

Time Complexity : O(N^2)
N -> size of nums

Memory Complexity : O(1)

What makes the algorithm run slowly ? 
1. the reason is because, for every index we need to recreate the left and right sub array

# Prefix Sum + Two Pointer
1. Loop from index 0 until nums.size() - 1 to get sum of right sub array
2. Loop from index 0 until nums.size() - 1, for every index we need to do these steps
   - Add the current number (nums[i]) to the prefixSumLeft
   - Decrease the current number (nums[i]) from the prefixSumRight
   - If the prefixSumleft >= prefixSumRight, increase the answer value by 1

Time Complexity : O(N + N)
N -> size of nums array
first N -> to create sum for right sub array
second N -> to get the answer

Memory Complexity : O(1)

*/

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int answer = 0;        
        long long prefixSumLeft = 0;
        long long prefixSumRight = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSumRight += nums[i];
        }

        for (int i = 0; i < nums.size() - 1; i++) {
            prefixSumLeft += nums[i];
            prefixSumRight -= nums[i];

            if (prefixSumLeft >= prefixSumRight) {
                answer++;
            }
        }

        return answer;
    }
};