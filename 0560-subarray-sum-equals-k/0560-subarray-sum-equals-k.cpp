/*

How to solve the problem : 

# Brute Force Approach
1. create all subarrays from array of nums
2. for every sub array, we need to check if the sum of that sub array if equal to k
   - if it is equal to K, we need to increase the count / answer

Time Complexity : O(N * 2)
N -> length array of nums

Memory Complexity : O(1)

# Prefix Sum + Hash Table Approach
1. loop for first index of nums array until last index of nums array
2. for every number in nums array we need to do these process
   - sum the current number and put the result in sum variable
   - to check whether the current sub array is equal to the K, we can use this formula (current sum - k = number in hash table), if number that we want to find in exist in hash table, we can increase the count of answer
   - put current sum variable value into hash table with key = current sum and value total current sum appear in these processes

edge cases : 
1. what if the current sum = k, that means we will find number 0, if that the case the default value of 0 in hash table should be 1, since the current sum is equal to the k

Time complexity : O(N)
N -> length of nums array

Memory complexity : O(N)
N -> length of nums array

*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int answer = 0;
        unordered_map<int,int> bucket;

        // put the default value, see the explanation above
        bucket[0] = 1;

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int find = sum - k;

            if (bucket[find] > 0) {
                answer += bucket[find];
            }

            bucket[sum]++;
        }

        return answer;
    }
};