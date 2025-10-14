/*

How to solve the problem

Main idea : 
1. using monotonic decreasing array to maintain the highest value
2. using pair stack to maintain the highest value and the lowest value

# Using stack
1. initialize variables
   - stack<pair<int,int>> st
   - lowestNumber = INT_MAX
2. loop for every number in nums array
   - if (st.size() > 0 && st.top().first < nums[i])
     - pop stack
   - if (st.size() > 0 && st.top().second < nums[i] && nums[i] < st.top().first)
     - return true, since we already fullfill the condition based on the problem description
   - get the lowest number
   - push {nums[i], lowest number} to the current stack
3. return false

Time Complexity : O(N)
N -> size of nums

Memory Complexity : O(M)
M -> size of stack
*/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // highest number, lowest number
        stack<pair<int,int>> st;
        int lowestNumber = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            
            while (st.size() > 0 && st.top().first < nums[i]) {
                st.pop();
            }

            if (st.size() > 0 && st.top().second < nums[i] && nums[i] < st.top().first) {
                return true;
            }

            lowestNumber = min(lowestNumber, nums[i]);
            st.push({nums[i], lowestNumber});
        }

        return false;
    }
};