/*

How to solve the problem : 

# Two pointer technique
1. left pointer must be put in the index 0
2. right pointer must be put in the index 1
3. we will start by sum from right to index 1
4. to get the answer at index i, we will multiply the total number that we get from (sum(0, left)) * sum(i + 1, right)
5. do step 4 from index 0 until nums.size() - 1

Time complexity : O(N + N)
N -> size of nums array
first N -> because of we need to loop from first index until last index in nums array
second N -> because of we need to precompute the number before do the process 4

Memory complexity : O(1)

# PrefixSum + SuffixSum
1. Create the suffixSum first
2. loop from first index of nums array until last index of nums array, for every process we need to do these steps
   2.1 multiply last number in the prefixSum (prefixSum[prefixSum.size() - 1]) with the currentNumber
3. to get the answer at index i, we can use this formula
   3.1 formula : prefixSum * suffixSum[nums.size() - i - 2]

Note : 
1. why using suffixSum[nums.size() - i - 2], the reason is because of we want to ignore the number in the current index, thats why we put -2 there
2. if index i == nums.size() - 1, we just need to use prefixSum value as our answer for that index, since using the current formula will get an error (index out of bounds)

Time Complexity : O(N)
N -> size of nums array

Memory Complexity : (N)
N -> size of nums array

Note : 
1. for prefix sum we can calculate that in the process without put the sum in the array

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> suffixSum;
        vector<int> answer;

        // create suffix sum array
        for (int i = nums.size() - 1; i >= 0; i--) {
            int number = nums[i];
            if (suffixSum.size() == 0) {
                suffixSum.push_back(number);
            } else {
                suffixSum.push_back(number * suffixSum[suffixSum.size() - 1]);
            }
        }

        int prefixSum = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (i == nums.size() - 1) {
                answer.push_back(prefixSum);
            } else {
                answer.push_back(prefixSum * suffixSum[suffixSum.size() - i - 2]);
            }

            prefixSum *= nums[i];
        }

        return answer;
    }
};