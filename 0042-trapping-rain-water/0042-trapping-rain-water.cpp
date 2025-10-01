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
1. initialize two pointer (left = 0 and right = size - 1)
2. initialize left max and right max (leftMax = height[left] and rightMax = height[right])
3. while left < right
   - if leftMax < rightMax, that means we pick the leftMax
     - increase left pointer by 1
     - update left max
     - add answer by left max - height[left]
   - else, that means we pick the right max
     - decrease right pointer by 1
     - update right max 
     - add answer by (right max - height[right]])

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
        int leftMax = height[left];
        int right = size - 1;
        int rightMax = height[right];

        while (left < right) {
            if (leftMax < rightMax) {
                left++;
                leftMax = max(leftMax, height[left]);
                answer += leftMax - height[left];
            } else {
                right--;
                rightMax = max(rightMax, height[right]);
                answer += rightMax - height[right];
            }
        }

        return answer;
    }
};