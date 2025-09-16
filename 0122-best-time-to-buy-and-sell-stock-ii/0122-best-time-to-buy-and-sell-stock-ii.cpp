/*

How to solve the problem : 

# Two Pointer Technique
1. Find the increasing sub array inside prices array
2. to maximize the result we need to get the element in the end of sub array - the element at start of sub array

Time Complexity : O(N)
N -> size of prices array

Memory Complexity : O(1)

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int answer = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i - 1] > prices[i]) {
                // calculate the answer
                answer += (prices[i - 1] - prices[left]);
                left = i;
            }
        }

        if (prices[prices.size() - 1] > prices[left]) {
            answer += prices[prices.size() - 1] - prices[left];
        }

        return answer;
    }
};