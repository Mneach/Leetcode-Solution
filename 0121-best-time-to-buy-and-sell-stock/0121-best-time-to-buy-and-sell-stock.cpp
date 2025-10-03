/*

How to solve the problem 

# Using two pointer
1. initialize left pointer, right pointer and result
2. loop from the first index of prices array until last index of prices array
   - if (prices[right] < prices[left])
     - move left pointer to right pointer
   - else
     - calculate the result using this formula : prices[right] - prices[left]
     - get the maximum result (result = max(result, prices[right] - prices[left]))
   - increase the right pointer by 1
3. return the result

Time Complexity : O(N)
N -> size of prices array

Memory Complexity : O(1)

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 0;
        int result = 0;

        while (right < prices.size()) {
            if (prices[left] > prices[right]) {
                left = right;
            } else {
                result = max(result, prices[right] - prices[left]);
            }

            right++;
        }

        return result;
    }
};