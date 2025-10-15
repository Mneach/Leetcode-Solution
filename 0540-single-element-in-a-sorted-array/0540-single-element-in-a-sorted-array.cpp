
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

Time Complexity : O(log N)
N -> size of nums

Memory Complexity : O(1)

*/

class Solution {
private:
    int findSingleElement(int left, int right, vector<int>& nums) {
        if (left > right) {
            return -1;
        }

        int mid = left + (right - left) / 2;
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
            return nums[mid];
        } else {
            int leftPart = findSingleElement(left, mid - 1, nums);
            if (leftPart != -1) {
                return leftPart;
            }

            int rightPart = findSingleElement(mid + 1, right, nums);
            return rightPart;
        }
    }
public:
    int singleNonDuplicate(vector<int>& nums) {

        if (nums.size() == 1) {
            return nums[0];
        }

        int result = findSingleElement(1, nums.size() - 2, nums);
        
        if (result == -1) {

            if (nums[0] != nums[1]) {
                result = nums[0];
            } else {
                result = nums[nums.size() - 1];
            }
        }

        return result;
    }
};