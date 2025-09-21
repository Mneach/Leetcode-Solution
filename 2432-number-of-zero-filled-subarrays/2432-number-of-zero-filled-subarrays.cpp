/*

How to solve the problem : 
1. loop from first index of the array until last index of the array
2. we need to get the subarray with value 0
3. count how many 0 appear in the sub array
4. to calculate how many combination that we can create, we can use this formula : (N * (N + 1)) / 2

Time Complexity : O(N)
N -> size of nums

Memory Complexity : O(1)

*/

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long answer = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            
            if (nums[i] == 0) {
                count++;
            } else {
                long long totalCombination = (1LL * count * (count + 1)) / 2;
                answer += totalCombination;
                count = 0;
            }
        }

        if (count != 0) {
            long long totalCombination = (1LL * count * (count + 1)) / 2;
            answer += totalCombination;
        }

        return answer;
    }
};