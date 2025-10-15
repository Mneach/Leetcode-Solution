
/*

How to solve the problem
1. initialize variables
   - left = 0
   - right = nums.size() - 1
   - result = 0
2. do binary search algorithm
   - while left <= right
     - mid = left + (right - left) / 2
     - if (nums[mid] == target)
       - result = mid
       - break
     - else if (nums[mid] < target) 
       - left = mid + 1
       - result = left
     - else 
       - right = mid - 1
3. return result

Time Complexity : O(log N)
N -> size of nums

Memory Complexity : O(1)

*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                result = mid;
                break;
            } else if (nums[mid] < target) {
                left = mid + 1;
                result = left;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};