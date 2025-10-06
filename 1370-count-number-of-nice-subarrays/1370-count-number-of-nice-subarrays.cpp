/*

How to solve the problem

# Using sliding window
1. initialize variables
   - left = 0
   - right = 0
   - count = 0
   - result = 0
2. while right < nums.size()
   - if (nums[right] == 1)
     - decrease the k by 1
   - if k == 0
     - reset count to 0
   - while k == 0
     - if nums[left] is an odd number, just increase the k value by 1
     - increaes left pointer by 1
     - increaes count by 1
   - add result by count value
   - increase right pointer by 1
3. return the result

Time Complexity : O(N)
N -> size of nums

Memory Complexity : O(1)

*/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left = 0;        
        int right = 0;
        int count = 0;
        int result = 0;

        while (right < nums.size()) {
            if (nums[right] % 2 == 1) {
                k--;
            }

            if (k == 0) {
                count = 0;

                while (k == 0) {
                    if (nums[left] % 2 == 1) {
                        k++;
                    }
                    left++;
                    count++;
                }
            }

            result += count;
            right++;
        }

        return result;
    }
};