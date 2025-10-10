/*

How to solve the problem 

# Using stack
1. initialize variables
   - stack<int> st
   - vector<int> results
2. loop from the first index of asteroids until last index of asteroids
   - bool skip = false
   - while st.size() > 0 && st.top() > 0 && asteroids[i] < 0
     - if (st.top() + asteroids[i] > 0)
       - skip = true
       - break
     - else if (st.top() + asteroids[i] < 0)
       - st.pop()
     - else
       - st.pop()
       - skip = true
       - break
   - if skip == false
     - then push asteroids[i] into the stack
3. loop for every data in the stack
   - put the number into the results array
4. reverse the result array
5. return the result array

Time Complexity : O(N + M + N / 2)
N -> size of asteroids array
M -> size of stacks

Memory Compelxity : O(M)
M -> size of stacks

*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> results;

        for (int i = 0; i < asteroids.size(); i++) {
            bool skip = false;

            while (st.size() > 0 && st.top() > 0 && asteroids[i] < 0) {
                if (st.top() + asteroids[i] > 0) {
                    skip = true;
                    break;
                } else if (st.top() + asteroids[i] < 0) {
                    st.pop();
                } else {
                    skip = true;
                    st.pop();
                    break;
                }
            }

            if (skip == false) {
                st.push(asteroids[i]);
            }
        }

        while (st.size() > 0) {
            results.push_back(st.top());
            st.pop();
        }

        reverse(results.begin(), results.end());

        return results;
    }
};