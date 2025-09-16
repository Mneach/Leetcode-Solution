/*

How to solve the problem : 
1. looping from first index of nums array to last index of nums array to find longest increasing and decreasing sub array

Time Complexity : O(N)
N -> size of an array

Memory Complexity : O(1)

*/

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int answer = 1;
        int inc = 1;
        int dec = 1;

        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] > nums[i - 1]) {
                inc++;
                answer = max(answer, dec);
                dec = 1;
            } else if (nums[i] < nums[i - 1]) {
                dec++;
                answer = max(answer, inc);
                inc = 1;
            } else {
                answer = max(answer, max(dec, inc));
                dec = 1;
                inc = 1;
            }
        }

        return max(answer, max(inc, dec));
    }
};