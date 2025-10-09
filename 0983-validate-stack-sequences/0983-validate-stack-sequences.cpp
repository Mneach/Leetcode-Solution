/*

How to solve the problem

# Using Stack
1. initialize variables
   - pushIndex = 0
   - popIndex = 0
   - stack<int> st
2. loop from the first index of pushed array until last index of pushed array
   - push pushed[pushIndex] to the stack
   - while (st.size() > 0 && st.top() == popped[popIndex])
     - st.pop()
     - popIndex += 1
   - pushIndex += 1
3. return st.size() == 0

Time Complexity : O(N + M)
N -> size of pushed array
M -> size of popped array

Memory Complexity : O(N)
N -> size of pushed array

# Can we improve the solution ? 
1. Yes we can, instead of using stack to maintain the state. it's better to use two pointer to maintain the stack, so we can reduce the memory complexity to O(1)

# Using Two Pointer
1. initialize variables
   - pushRightIndex = 0
   - popIndex = 0
   - pushLeftIndex = 0
2. while pushRightIndex < pushed.size()
   - if (pushed[pushRightIndex] != popped[popIndex])
     - change pushed[pushLeftIndex] to pushed[pushRightIndex]
       - you can image that its something like push the data into top of the stack
     - increase the pushLeftIndex pointer
   - else
     - increase popIndex by 1
     - while pushLeftIndex > 0 && pushed[pushLeftIndex - 1] == popped[popIndex]
       - you can image that, its something like, we try to compare the data from top of the stack with the popped[popIndex] data
       - decrease pushLeftIndex by 1
       - increase the popIndex by 1
   - increase the pushRightIndex
3. return pushLeftIndex == 0

Time Complexity : O(N + M)
N -> size of pushed array
M -> pushLeftIndex value

Memory Compelxity : O(1)

*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int pushLeftIndex = 0;
        int pushRightIndex = 0;
        int popIndex = 0;

        while (pushRightIndex < pushed.size()) {
            if (pushed[pushRightIndex] != popped[popIndex]) {
                // maintain the state
                pushed[pushLeftIndex] = pushed[pushRightIndex];
                pushLeftIndex++;
            } else {
                popIndex++;

                while (pushLeftIndex > 0 && pushed[pushLeftIndex - 1] == popped[popIndex]) {
                    pushLeftIndex--;
                    popIndex++;
                }
            }

            pushRightIndex++;
        }

        return pushLeftIndex == 0;
    }
};