
/*

# Observation
1.	Suppose an array of length n sorted in ascending order is rotated between 1 and n times
2. We need to find the minimum element of this array

# Idea
1.	to check if the nums[i] = minimum element, nums[i] < nums[i - 1] && nums[i] < nums[i + 1]
   - if i == 0, then nums[i - 1] should be replace to nums[n - 1]
   - if i == nums.size() - 1, then nums[i + 1] should be replace to nums[0]
2. definition
   - prevNumber = nums[i - 1]
   - nextNumber = nums[i + 1]
   - currNumber = nums[i]
3. using left and right pointer to determine where should we move
   - if nums[left] > nums[right] && nums[left] <= nums[mid]
     - we know that the minimum element should be in between mid and right pointer
     - move left pointer to mid + 1
   - else
     - move right pointer to mid - 1

# Brute Force Solution

       I
[3,4,5,1,2]

prevNumber = 5
currNumber = 1
NextNumber = 2

result = 1

# Pseudecode
1.	result = -1
2.	loop from the first index of nums array until last index of nums array
   - prevNumber, nextNumber
   - currentNumber = nums[i]
   - if i == 0, then prevNumber = nums[nums.size() - 1]
   - else, then prevNumber = nums[i - 1]
   - if i == nums.size(), then nextNumber = nums[0]
   - else, then nextNumber = nums[i + 1]
   - if (currNumber < prevNumber && currNumber < nextNumber) 
     - result = currNumber
     - break
3. return the result

Time Complexity : O(N)
N -> size of nums

Memory Complexity : O(1)

# Binary Search

# Simulation

[3,4,5,6,7,8,1,2]

left = 5
right = 8
mid = 6

prevNumber = 8
currentNumber = 1
nextNumber = 2


[1,2,3,4,5,6,7,8]

left = 7
right = 7
mid = 7

prevNumber = 7
currentNumber = 8
nextNumber = 1


[1,2,3,4,5,6,7,8]

left = 7
right = 8
mid = 9

prevNumber = 8
currentNumber = 1
nextNumber = 2

# Pseudecode
1.	initialize variables
   - left = 0
   - right = newNums.size() - 1
2. while left <= right (do binary search algorithm)
   - mid = left + (right - left) / 2
   - prevNumber 
   - if i == 0, then prevNumber = nums[nums.size() - 1]
   - else, then prevNumber = nums[i - 1]
   - if i == nums.size(), then nextNumber = nums[0]
   - else, then nextNumber = nums[i + 1]
   - if (currNumber < prevNumber && currNumber < nextNumber)
     - return currNumber
   - if (nums[left] > nums[right] && nums[left] <= nums[mid]
     - left = mid + 1
   - else
     - right = mid - 1

Time Complexity : O(log N)

Memory Complexity : O(1)

*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int currentNumber = nums[mid];
            
            int prevNumber = mid == 0 ? nums[nums.size() - 1] : nums[mid - 1];
            int nextNumber = mid == nums.size() - 1 ? nums[0] : nums[mid + 1];

            if (currentNumber <= prevNumber && currentNumber <= nextNumber) {
                result = currentNumber;
                break;
            }

            if (nums[left] > nums[right] && nums[left] <= nums[mid]) {
                // the minimum element should be in between mid and right pointer
                left = mid + 1;
            } else {
                // the minimum element should be in between left and mid pointer
                right = mid - 1;
            }
        }

        return result;
    }
};