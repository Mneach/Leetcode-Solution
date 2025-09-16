/*

How to solve the problem :

# Using brute force solution
1. Create all posibillity subarray that we can get from nums array
2. sum those subarrays, if the sum dibisible by k, increase the answer variable by 1

Time Complexity : O(N^2)
N -> size of nums array

Memory Complexity : O(1)

# What makes the algorithm run slower ? 
1. we need to create all posibillity subarray from array nums

# Using hashtable
1. We need to think the number as a group (subarray) not an individual number
2. Create the prefix sum from nums array, so that can make us easily to construct the subarray that divisible by K. Divide the number in prefix sum by k, so later we just need to find / eliminate the remaining value of the current subarray
3. To know if this subarray is divisible by K, we need to find / eliminate the remaining value of the current subarray  
4. Loop from the first index of nums array until the last index of nums array, check if we can find the remaining value of the current subarray, 
   - if we can find, add the hashtable[prefixSum[i]] value to the answer, and we can put that into hashtable with key = current prefix sum value and value = total that number appear in prefix sum
   - otherwise, just move to the next index


Edge cases : 
1. create hashtable[0] with default value 1, since 0 is already divisible by K

Time Complexity : O(N + N)
N -> size of nums array

Memory Complexity : O(K - 1)
K -> number divisor

*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> bucket;
        vector<int> prefixSum;
        int answer = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (prefixSum.size() == 0) {
                prefixSum.push_back(nums[i]);
            } else {
                prefixSum.push_back((nums[i] + prefixSum[prefixSum.size() - 1]));
            }
        }

        // edge cases
        bucket[0] = 1;

        for (int i = 0; i < prefixSum.size(); i++) {
            int remaining = ((prefixSum[i] % k) + k) % k;
            
            answer += bucket[remaining];
            bucket[remaining]++;
        }

        return answer;
    }
};