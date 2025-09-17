/*

How to solve the problem : 

# Hash Table

Math Formula
SUM -> sum of nums array % p
prefixSumRight[i] -> prefixSumRight[0 - i]
prefixSumLeft[j] -> prefixSumLeft[0 - j]
(prefixSumRight[i] - prefixSumLeft[j]) -> to find the smallest array that can be remove to make the current SUM divisible by P

to find the smallest sub array that we need to remove so the sum can be divisible by p, we need to use this formula
(SUM - (prefixSumRight[i] - prefixSumLeft[j])) % p = 0

The problem is we didn't know the value of prefixSumLeft, so to find the prefixSumLeft, we need to change the math equation

(SUM - (prefixSumRight[i] - prefixSumLeft[j])) % p = 0
SUM = (prefixSumRight[i] - prefixSumLeft[j]) % p
prefixSumLeft[j] = (prefixSumRight[i] - SUM)  %p

Because prefixSumRight[i] - SUM can be negative we need to add +p to the formula, to make sure the result alwasy positive
prefixSumLeft[j] = ((prefixSumRight[i] - SUM) + p )% p

1. to construct SUM value we need to loop from the first index of nums until last index of nums
2. to get the answer, loop from the first index of nums until last index of nums
   - calculate the prefixSumRight by adding the variable by nums[i] % p
   - to find the prefixSumleft we can use the formula above
   - find the prefixSumLeft in hashtable, if the data is already exists in hashtable, that means, there is a subarray that we can remove from nums so the SUM can be divisible by P
      - to compute the total sub array that we need to remove, we just need to use formula : i - hashtable[prefixSumLeft], i - hashtable[prefixSumLeft] = size of subarray
   - put the prefixSumRight into the hashtable, key = prefixSumRight value = index

Clarification : 
1. Why we alwasy need to update the currentSum value index in hashtable, the reason is because of we want to get the smallest index of array that can be remove from nums array, so the SUM can be divisible by P. If we didnt update the currentSum value in hashtable, the gap between the same currentSum value will be larger that means we need to delete a lot of numbers 

edge cases : 
1. what if P is more than sum of all the numbers in nums array ? 
   - we need to return -1, we dont need to do anything
2. what if the result of prefixSumLeft = 0 ? 
   - we will mark 0 with value -1 in hashtable, the reason is because of, if the result = 0, we dont need to remove any number in nums array

Time Complexity : O(N + N)
N -> size of nums
first N -> to construct SUM
second N -> to get the answer

Memory Complexity : O(M)
N -> hashtable size

*/

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int,int> bucket;
        int SUM = 0;
        int answer = nums.size();

        for (auto num : nums) {
            SUM = (SUM + num) % p;
        }

        // basecase, that means we didn't need to remove any number from nums array
        if (SUM == 0) return 0;
        
        bucket[0] = -1;

        int prefixSumRight = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefixSumRight = (prefixSumRight + nums[i]) % p;

            int prefixSumLeft = ((prefixSumRight - SUM) + p) % p;

            if (bucket.count(prefixSumLeft) > 0) {
                answer = min(answer, i - bucket[prefixSumLeft]);
            }

            bucket[prefixSumRight] = i;
        }

        if (answer == nums.size()) {
            return -1;
        }

        return answer;
    }
};