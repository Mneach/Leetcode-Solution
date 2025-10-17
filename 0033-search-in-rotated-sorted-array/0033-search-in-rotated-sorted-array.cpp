/*

# Observation
1.	array sorted in asc order, but the array possibly left rotated at an unknown index k 
2.	We need to find the target in the sorted array
   - if the target exists, need to return the index
   - else, return -1

# Brute force solution

# Simulation
                I
nums = [4,5,6,7,0,1,2], target = 0
nums[i] = 0
result = 5

nums = [4,5,6,7,0,1,2], target = 3
nums[i] = 0
result = -1

# Pseudecode
1.	initialize variables
 - result = -1
2.	loop from the first index until last index
   - check if nums[i] == target, then update result = i
3. return the result

Time Complexity : O(N)
N -> size of nums

Memory Complexity : O(1)

# Binary Search

# Observation
1.	We can have maximum 2 sorted array, after we rotate the array
2.	nums[left] > nums[right], that means we are in different sorted array
    - nums[left] - nums[mid] should be left part sorted array
    - nums[mid] - nums[right] should be right part sorted array

# Simulation

nums = [4,5,6,7,0,1,2], target = 0

left = 4
right = 6
mid = 5

                 L
                 M
                 R
nums = [4,5,6,7][0,1,2]

if (nums[mid] == target) 
⦁	return mid
else if (nums[left] > nums[right] && nums[left] > target)
⦁	move left pointer to mid + 1
else
⦁	move right pointer to mid - 1


nums = [4,5,6,7,0,1,2], target = 4

left = 0
right = 0
mid = 0

        L
        M
        R
nums = [4,5,6,7][0,1,2]

if (nums[mid] == target)
⦁	return mid
else if (nums[left] > nums[right] && nums[left] > target)
⦁	move left pointer to mid + 1
else
move right pointer to mid - 1

# Pseudocode
1.	initialize variables
   - left = 0
   - right = nums.size() - 1
   - result = -1
2. while left <= right (do binary search algorithm)
   - int mid = left + (right - left) / 2
   - if (nums[mid] == target)
     - result = mid
     - break
   - else if (nums[left] <= nums[mid]) 
     - left part sorted array
     - if (nums[mid] < target || nums[left] > target)
       - // target should be in right part
       - left = mid + 1
     - else
       - right = mid - 1
   - else
     - right part sorted array
     - if (nums[mid] > target || nums[right] < target)
       - target should be in left part
       - right = mid - 1
     - else
       - left = mid + 1
3. return the result

Time Complexity : O(log N)
N -> size of nums array

Memory Complexity : O(1)

target = 8
 	 L
               R
[4,5,6,7,8,1,2,3]

nums[left] > nums[right] && nums[mid] < target && nums[left] < target

left = 5
right = 4

         L
                 R
[4,5,6,7,8,0,1,2,3]


[4,1,2,3]

[1,2,3,4,5,6,7,8,9,10]

target = 3

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
            } else if (nums[left] <= nums[mid]) {
                // left part sorted array

                if (nums[mid] < target || nums[left] > target) {
                    // target should be in right part
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                // right part sorted array
                if (nums[mid] > target || nums[right] < target) {
                    // target should be in left part
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        return result;
    }
};