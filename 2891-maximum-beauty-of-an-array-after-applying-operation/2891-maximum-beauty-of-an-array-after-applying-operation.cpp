
/*

how to solve : 

# Binary Search
1. sort the nums
2. search number between range nums[i] until nums[i] + k
3. to implement that we can use binary search, search from nums[i] until nums[i] - k
   - the reason of nums[i] - k, is because we can replace nums[i] with nums[i - k]
   - so to maximize the window, we can search from nums[i] until nums[i] -k

Timecomplexity: O(N log n) + N log n
- first N log n -> from sort the data
- second N log n -> from implement binary search

Memorycomplexity : O(1)
- we dont need any additinoal memory

# Two pointer technique
1. sort the nums
2. implement two pointer technique to get the answer
   - we need to move left pointer, if (nums[right] - k) - nums[left] > k
   - otherwise, just move the right pointer and keep calculate the max answer

Time Complexity : O(N log n) + n
- first N log n -> from sort the data 
- second n -> loop from first element until last element in nums

Memory Complexity : O(1)
- we dont need additional memory complexity

*/

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
       sort(nums.begin(), nums.end());
       int size = nums.size();
       int answer = 0;

       int left = 0;
       for (int right = 0; right < size; right++) {
            int current = nums[right] - k;

            while (left < right && current - nums[left] > k) {
                left++;
            }

            if (current - nums[left] <= k) {
                answer = max(answer, (right - left) + 1);
            }
       }

       answer = max(answer, size - left);

       return answer;
    }
};