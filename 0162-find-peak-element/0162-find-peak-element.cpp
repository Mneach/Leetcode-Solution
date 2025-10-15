/*

Rules : 
1. peak number = nums[i] > nums[i - 1] && nums[i] > nums[i + 1]
2. i == 0, then nums[i - 1] = -infinity
3. i == nums.size(), then nums[i + 1] = -infinity

# Using brute force 

1. loop from the first index of array until last index of array
   - if the current index is a peak number
     - return current index

Time Complexity : O(N)
N -> size of nums array

Memory Complexity : O(1)

# Can we improve the solution
1. Yes we can, instead of using linear search to find a pick number, we can use binary search to find a pick number. The main idea is, we just need to find the higest number in the current sub array (nums[L] until nums[R]), because the highest number in the current sub array should be a peak number, so need to follow these rules
   - if nums[i] < nums[i + 1], then move to the right part. Because we know that the higest number should be in the right part of the i index
   - if nums[i] < nums[i - 1], then move to the left part. Because we know that the highest number should be in the left part of the i index

# Using Binary Search
1. Initialize variables
   - left = 0
   - right = nums.size() - 1
2. while left <= right (binary sesarch algorithm)
   - mid = left + (right - left) / 2
   - currentNumber = nums[mid]
   - prevNumber
   - nextNumber
   - if (mid == 0), then prevNumber = INT_MIN
   - else, then prevNumber = nums[mid - 1]
   - if (mid == nums.size() - 1), then nextNumber = INT_MIN
   - else, then nextNumber = nums[mid + 1]
   - if currentNumber is a peak number
     - return mid
   - else if (currentNumber < nextNumber)
     - left = mid + 1
   - else
     - right = mid - 1
3. return -1

Time Complexity : O(log N)
N -> size of nums

Memory Complexity : O(1)

*/


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int currentNumber = nums[mid];
            long long prevNumber;

            if (mid == 0) {
                prevNumber = LLONG_MIN;
            } else {
                prevNumber = nums[mid - 1];
            }

            long long nextNumber;
            if (mid == nums.size() - 1) {
                nextNumber = LLONG_MIN;
            } else {
                nextNumber = nums[mid + 1];
            }

            if (currentNumber > prevNumber && currentNumber > nextNumber) {
                return mid;
            } else if (currentNumber < nextNumber) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
};