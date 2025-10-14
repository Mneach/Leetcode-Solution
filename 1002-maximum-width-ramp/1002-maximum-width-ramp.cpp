/*

How to solve the problem

Main Idea : 
1. Need to find the next greater element from nums[i]

# Using stack
1. initialize variables
   - stack<int> st
   - i = 0
   - result = 0
2. loop for every number in nums array to construct next greater element
   - if stack is empty
     - push i to stack
   - else if (stack.top() < nums[i])
     - push i to the stack
3. while st.size() > 0 && i < nums.size()
   - int j = stack.top()
   - if nums[i] > nums[j]
     - i++
   - else
     - result = max(result, j - index)
     - stack.pop()
4. return the result

Time Complexity : O(N + N) 
N -> size of nums

Memory Complexity : O(M)
M -> size of stack

*/

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int i = 0;
        int result = 0;
        stack<int> st;

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (st.empty()) {
                st.push(i);
            } else {
                int number = nums[st.top()];

                if (number < nums[i]) {
                    st.push(i);
                }
            }
        }

        while (st.size() > 0 && i < nums.size()) {
            int j = st.top();
            if (nums[i] > nums[j]) {
                i++;
            } else {
                result = max(result, j - i);
                st.pop();
            }
        }

        return result;
    }
};