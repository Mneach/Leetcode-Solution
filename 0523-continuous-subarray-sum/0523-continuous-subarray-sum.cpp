/*

How to solve the problem : 

# Brute Force Solution :
1. Create all of the combination of sub array
2. for every sub array we need to sum the sub array and check if the sum can be divisible by K
3. if sum can be divisible by K, return true

Time Complexity : O(N^2)
N -> size of nums array

What makes the algorithm run slower ? 
1. Because we need to create all of the sub array combination

How to improve ? 
1. We can use the prefix sum to get the sub array and check if the current sum can be divisible by k

# Hashtable
1. Loop from the first index of nums array until the last index of nums array, and do these steps
   - Add the nums[i] to the current sum and modulo current sum by K
   - if nums[i] already exists in hashtable, we need to check the distance between the current index with the hashTable
     - if the distance > 1 return true, since we need to create atleast subarray with length two
   - otherwise, put the current sum into the hashtable

edge cases : 
1. what if for the first time the currentSum result = 0 ? ex : [1,2,4] K = 3
   - we need to add default value for number 0 in hashtable, hashTable[0] = -1
   - we need to add that value because by default if the modulo result == 0, that means the current sum can be divisible by K
   - why we put -1 as a default value ? because of the index of the subarray of prefixSum start from 0

Time Complexity : O(N)
N -> nums of size array

Memory Complexity : O(K - 1)
K -> divisor

*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> hashTable;

        hashTable[0] = -1;

        int currentSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            currentSum = (currentSum + nums[i]) % k;

            if (hashTable.count(currentSum) > 0) {
                int distance = i - hashTable[currentSum];

                if (distance > 1) {
                    return true;
                }
            } else {
                hashTable[currentSum] = i;
            }
        }

        return false;
    }
};