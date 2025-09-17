/*

How to solve the problem : 
1. loop from i = 0 until i < nums.size() to construct prefixSumLeft
2. loop from i = nums.size() - 1 until i = 1, for every process we need to do this to get the answer
   - decrease prefixSumLeft by nums[i]
   - if prefixSumleft == prefixSumRight then we mark that index as an aswer
   - increase prefixSumRight by nums[i]
3. check if the answer == nums.size(), that means we cannot find the answer so just return -1, otherwise return the answer value

Time Complexity : O(N + N)
N -> size of nums array
first N -> to compute prefix sum left
second N -> to compute the answer

Memory Complexity : O(1)

*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int answer = nums.size();
        int prefixSumLeft = 0;
        int prefixSumRight = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSumLeft += nums[i];
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            prefixSumLeft -= nums[i];
            if (prefixSumLeft == prefixSumRight) {
                answer = i;
            }
            prefixSumRight += nums[i];
        }

        if (answer == nums.size()) return -1;

        return answer;
    }
};