/*

How to solve the problem 

# Using Two Pointer Technique
1. Initialize left and right pointer
2. left = 0 and right = height.size() - 1
3. while left < right
   - take the minimum height between heigh[left] and height[right]
   - calculate the distance between those indexes using this formula : right - left
   - calculate the current answer using this formula : minHeight * distance
   - compare that current answer to the real answer variable
   - if nums[left] > nums[right], decrease the right pointer by 1  
   - else if nums[left] < nums[right], increase left pointer by 1

Time Complexity : O(N)
N -> size of height array

Memory Complexity : O(1)

*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int answer = 0;

        while (left < right) {
            int minimumHeight = min(height[left], height[right]);
            int distance = right - left;
            int currentAnswer = minimumHeight * distance;
            answer = max(answer, currentAnswer);

            if (height[left] > height[right]) {
                right--;
            } else if (height[left] < height[right]) {
                left++;
            } else {
                left++;
            }
        }

        return answer;
    }
};