
/*

How we can solve the problem

# Using brute force solution
1. loop from first index until last index of nums
   - if nums[i] != nums[i - 1] && nums[i] != nums[i + 1]
     - return nums[i]
2. return -1

Time Complexity : O(N)
N -> size of nums

Memory Compelxity : O(1)

# Can we improve the solution
1. Yes we can, instead of using linear search to find the answer, we can use binary search and recursive to find the answer

# Using binary search + recursive
1. basecase
   - if (nums.size() == 1)
     - return nums[0]
2. recursive functions
   - basecase
     - if left > right, return -1
   - int mid = left + (right - left) / 2
   if nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]
     - return nums[mid]
   - else
     - leftPart = recursive(left, mid - 1, nums)
     - if leftPart != -1 return leftPart
     - rightPart = recursive(mid + 1, right, nums)
     - if rightPart != -1 return rightPart
     - return -1
3. call recursive function

Time Complexity : O(N)
N -> size of nums

Memory Complexity : O(N)

# Can we improve the solution again
1. Yes we can, the idea if the current mid is not our answer, we need to move either to the left or to the right
2. since we know that all of the numbers appear twice, except the answer, by default
   - if mid == even index, than means nums[mid] == nums[mid + 1]
   - if mid == odd index, that means nums[mid] == nums[mid - 1]
3. if the current condition is not full fill that rules, we need to move the left or right pointer
   - if mid == even index && nums[mid] != nums[mid + 1], that means the answer should be in the left of the current mid
     - so move the right pointer to the mid - 1
   - else
     - move the left pointer to the mid + 1

# Using binary search
1. initialize variables
   - left = 0
   - right = nums.size() - 1
   - result = 0
2. we will start binary search from index 1 until nums.size() - 1 
3. return result

Time Complexity : O(log N)
N -> size of nums

Memory Complexity : O(1)

*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int result = 0;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (mid % 2 == 1) {
                // to make mid = even index
                mid--;
            }
            
            if (nums[mid] != nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 2;
            }
        }
        

        return nums[left];
    }
};