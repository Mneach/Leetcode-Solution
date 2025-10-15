
/*

How to solve the problem

# Using brute force solution
1. loop from the first index of nums until last index of nums
   - if nums[i] == target
     - return i
2. return -1

Time Complexity : O(N)
N -> size of nums

Memory Complexity : O(1)

# Can we improve the solution 
1. Yes we can, instead of using linear search to find the target, we can use binary search to find the target, so we can reduce the time complexity to become O(log N)

# Using binary search
1. initialize variables
   - left = 0
   - right = nums.size() - 1
   - result = 0
2. perform binary search to find the target
3. if target is not found, return -1
4. else return result

Time Complexity : O(log N)
N -> size of nums array

Memory Complexity : O(1)

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                result = mid;
                break;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};