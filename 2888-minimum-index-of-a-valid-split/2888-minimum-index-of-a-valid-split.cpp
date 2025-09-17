/*

How to solve the problem : 

# Brute Force Solution
1. for every index, create left sub array and right subarray
   - left sub array (nums[0 - i])
   - right sub array (nums[i + 1 - nums.size() - 1])
2. Create left sub array that contain a value of dominant element at index i
   - to create the left sub array we can start from index 0 until nums.size() - 1, for every index we need to find the dominant element by looping from left to right of subarray 
3. Create right sub array that containa value of dominant element at index i
   - to create the right sub array we can loop from nums.size() - 1 until index, for every index we need to find the dominant element by looping from left to right of sub array
   - if the left dominant sub array == right dominant sub array then mark that index as answer
   - if we find another index that have a value < current answer, then update the answer

# Time Complexity : O(N^2 + N^2)
N^2 -> to create the sub array and find the dominant element

# Memory Complexity : O(M)
N -> size of left array

What makes the algorithm run slower ? 
1. Because we need to loop for every sub arrray to find the dominant element at index i 

How to improve ? 
1. Using hashtable to find the dominant element at index i

# Using Hash Table Approach
1. Loop from the first index of nums array until last index of nums array to construct the left array
   - To find the dominant element at index 1, we can use this formula (hashtable[nums[i]] * 2 > i)
   - if the condition is valid, we will add that dominant element as a value at index i in left array
   - otherwise, we will add -1 as a value at index i in left array
2. Loop from the last index of nums array until first index of nums array to know the dominant element for right sub array and to get the answer
   - To find the dominant element at index 1, we can use this formula (hashtable[nums[i]] * 2 > 1)
   - if the condition is valid, we need to check if the current dominant element == dominant element from left sub array, then mark that index as an answer
   - to get the dominant element from left sub array we can use leftArray[i - 1]
   - put the current number into hashtable

edge cases : 
1. what if the nums array only contain 1 number ? 
   - return -1, since we cannot split the array

Time Complexity : O(N + N)
N -> size of nums array

Memory Complexity : O(M + O + P)
M -> size of left sub array
O -> hash table for left sub array
P -> hash table for right sub array

*/

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> leftBucket;
        unordered_map<int,int> rightBucket;
        vector<int> leftArray(nums.size(), -1);
        int answer = -1;

        int prevNumber = -1;
        int prevTotal = 0;
        for (int i = 0; i < nums.size(); i++) {
            int number = nums[i];
            leftBucket[number]++;

            if (leftBucket[number] > prevTotal) {
                prevNumber = number;
                prevTotal = leftBucket[number];
            }

            if (prevTotal * 2 > (i + 1)) {
                leftArray[i] = prevNumber;
            }
        }

        prevNumber = -1;
        prevTotal = 0;
        for (int i = nums.size() - 1; i >= 1; i--) {
            int number = nums[i];
            rightBucket[number]++;
            
            if (rightBucket[number] > prevTotal) {
                prevNumber = number;
                prevTotal = rightBucket[number];
            }

            if (prevTotal * 2 > nums.size() - i) {
                if (prevNumber == leftArray[i - 1]) {
                    answer = i - 1;
                }
            }
        }

        return answer;
    }
};