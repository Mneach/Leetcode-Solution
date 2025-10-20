/*

# Observation
⦁	lower <= nums[i] + nums[j] <= upper
  - lets assume that we pick nums[i], that means we can change the formula to become like this
  - lower - nums[i] <= nums[j] <= upper - nums[i]
  - need to get most left pointer where current number >= the lower - nums[j]
  - need to get most right pointer where current number <= upper - nums[j]
  - we need to count the pair between those pointers
    - we can use this formula to count the pair, formula : (mostRightPointer - mostLeftPointer) + 1
⦁	i < j
  - Everytime we run binary search algorithm, we need to start left pointer at index i, not 0

# Using Binary Search

# Simulation

        I
nums = [0,1,4,4,5,7], lower = 3, upper = 6

nums[i] = 0

lower - nums[i] <= nums[j] <= upper - nums[i]

3 - 0 <= nums[j] <= 6 - 0

3 <= nums[j] <= 6

⦁	we need to find most left pointer where nums[j] >= 3

mostLeftPointer = 2

     L
   M
   R
[0,1,4,4,5,7]



we need to find most right pointer where nums[j] <= 6

           L
           M
         R
[0,1,4,4,5,7]

mostRightPointer = 4


to get the total pair we can use this formula = (mostRightPointer - mostLeftPointer) + 1


1.	initialize variables
   - result = 0
2.	sort nums asc
3.	loop for every number in nums array
   - newLower = lower - nums[i]
   - newUpper = upper - nums[i]
   - do binary search to get the most left pointer for the lower
   - do binary search to get the most right pointer for the upper
   - count the total pair using this formula (mostRightPointer - mostLeftPointer) + 1
   - result += count
4. return result;

Time Complexity : O(N log N + N log N)
N -> size of nums array

first N log N -> come from the sorting algorithm
second N log N -> to get the pair for every number in the nums array

Memory Complexity : O(1)

*/

class Solution {
private: 
    int findMostLeftPointer(vector<int> &nums, int left, int right, int target) {
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] >= target) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }

    int findMostRightPointer(vector<int> &nums, int left, int right, int target) {
        int result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] <= target) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long result = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++) {
            int newLower = lower - nums[i];
            int newUpper = upper - nums[i];

            int left = i + 1;
            int right = nums.size() - 1;

            int mostLeftPointer = findMostLeftPointer(nums, left, right, newLower);
            int mostRightPointer = findMostRightPointer(nums, left, right, newUpper);

            if (mostLeftPointer == -1 || mostRightPointer == -1) {
                continue;
            }

            int count = (mostRightPointer - mostLeftPointer) + 1;
            result += count;
        }

        return result;
    }
};