/*

How to solve the problem : 

# Using Brute Force Solution
1. loop from first index of height until last index of height
2. for every index we need to do these steps
   - find the greater element from height[i - 1] until height[0]
   - find the greater element from height[i] until height[size - 1]
   - to know how many water that we can get, we can use this formula
     - formula : min(height[left], height[right]) - height[i]

Time Complexity : O(N^2)
N -> size of height array

Memory Compelxity : O(1)

# What makes the algorithm run slowly ? 
1. Because for every index we need to find the greater element

# How to improve the solution ? 
1. what if we create the precompute array, so we can know the next greater element
   - create 2 array for left greater element and right greater element

# Using Greedy
1. precompute for left greater element and right greate element
2. loop from first index of height array until last index of height array
3. to know how many water that we can get at position i, we can use this formula
   - formula : min(left[i], right[i]) - height[i]

Time Complexity : O(N + N)
N -> size of height array

Memory Complexity : O(M + P)
M -> size of left array
P -> size of right array

*/

class Solution {
public:
    int trap(vector<int>& height) {
        int answer = 0;
        int size = height.size();
        vector<int> left(size, 0);
        vector<int> right(size, 0);

        for (int i = 0; i < size; i++) {

            if (i == 0) {
                left[i] = height[i];
                right[size - i - 1] = height[size - i - 1];
                continue;
            }

            left[i] = max(left[i - 1], height[i]);
            right[size - i - 1]  = max(right[size - i], height[size - i - 1]);
        }

        for (int i = 0; i < size; i++) {
            answer += min(left[i], right[i]) - height[i];
        }

        return answer;
    }
};