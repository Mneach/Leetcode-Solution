/*

How to solve the problem

# Using Greedy + Two Pointer
1. initialize two pointer (left = 0 and right = 1)
2. Loop for every color in colors array
3. while (right < colors.size())
   - while (right < colors.size() && colors[left] == colors[right])
     - if neededTime[left] > neededTime[right]
       - add answer variable by neededTime[left]
       - right++
     - else
       - add answer variable by neededTime[right]
       - left = right, because we want to keep the right one


Time Complexity : O(N)
N -> size of colors array

Memory Complexity : O(1)

*/

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int left = 0;        
        int right = 1;
        int answer = 0;

        while (right < colors.size()) {
            if (colors[left] != colors[right]) {
                left = right;
            } else {
                if (neededTime[left] < neededTime[right]) {
                    // we will take left ballon
                    answer += neededTime[left];
                    left = right;
                } else {
                    // we will take right ballon
                    answer += neededTime[right];
                }
            }

            right++;
        }

        return answer;
    }
};