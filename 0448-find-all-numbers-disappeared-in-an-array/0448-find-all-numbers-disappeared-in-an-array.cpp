/*

How to solve the problem : 

# Brute Force Solution
1. search the number start from 1 to n, if we canoot find the current number in nums array, we push that number into the answer array 

Time Complexity : O(N^2)
N -> size of nums array

Memory Complexity : O(N)
N -> size of answer array

What makes the algorithm run slower ? 
1. Because we need to loop for every number from 1 to n, and find that number in nums array

# Sorting Algorihtm
1. sort the nums array
2. loop from first index of nums until last index of nums
3. if we find the gap between nums[i - 1] and nums[i]
4. loop from nums[i - 1] + 1 until nums[i] - 1, put those numbers in the array answer

Time Complexity : O(N log n + M)
N -> size of nums array
N log n -> sorting algorithm 
last M -> iterate all the numbers in nums array to get the answer

# Hashtable
1. construct hashTable with key = number, value = 1
2. loop from 1 to n, to construct hashTable
3. loop from first index of nums array until last index of nums array
   - decrease the hashTable[nums[i]] value by 1
4. loop for every data in hashTable
   - if the value of the current key > 0
   - put that number into the answer array

Time Complexity : O(N + N + M)
N -> size of nums array
M -> size of hashtable
first N -> to construct hashtable
second N -> to construct the answer
last M -> to get the answer

Memory Complexity : O(K + M)
K -> size of answer array
M -> size of hashTable

# Using Native Approach
1. Loop for every number in nums, mark the current index with negative value
2. Loop from 0 to nums.size(), if nums[i] > 0, then add (i + 1) to the answer array. 

Time Complexity : O(N + N) -> O(N)
N -> size of array

Memory Complexity : O(1)

*/


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> answer;

        for (int i = 0; i < nums.size(); i++) {
            // because the index start from 0
            int index = abs(nums[i]) - 1;
            nums[index] = -abs(nums[index]);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                answer.push_back(i + 1);
            }
        }

        return answer;
    }
};