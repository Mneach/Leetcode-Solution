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

# What makes the solution 2 run slowly and make more space ? 
1. because we need to precompute the left and right array 

# How to improvel the solution ? 
1. what if we just need to save the next greater element using two pointer left and right

# Using Two Pointer
1. loop from first index of height array until last index of height array
2. if left == right
   - find next greater right element
3. if height[i] >= left
   - update left pointer to i
4. to computer how many water that we can get, we can use this formula
   - formula : min(height[left], height[right]) - height[i]

Time Complexity : O(N + N)
N -> size of height array

Memory Complexity : O(1)

*/

class Solution {
public:
    int trap(vector<int>& height) {
        int answer = 0;
        int size = height.size();
        int left = 0;
        int right = 0;

        for (int i = 0; i < size; i++) {

            if (height[i] >= height[left]) {
                left = i;
            }

            if (i == right) {
                // find next right greater element
                right++;
                for (int j = right + 1; j < size; j++) {
                    if (height[j] >= height[right]) {
                        right = j;
                    }
                }

                continue;
            }

            answer += min(height[left], height[right]) - height[i];

        }

        return answer;
    }
};