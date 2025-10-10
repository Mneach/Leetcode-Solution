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

# Can we improve the solution ?
1. Yes we can, i think we can reduce the memory. So the idea of using stack in the solution above is to maintain the state. So to improve the solution we can try to use two pointer to maintain the state instead of using stack 

# Using Two Pointer
1. Initialize variables
   - left = 0
   - right = 0
   - vector<int> results
2. while right < asteroids.size()
   - bool skip = false
   - while (left > 0 && asteroids[left - 1] > 0 && asteroids[right] < 0)
     - if (asteroids[left - 1] + asteroids[right] > 0)
       - skip = true
       - break
     - eles if (asteroids[left - 1] + asteroids[right] < 0)
       - decrease left pointer by 1 (you can imangine its like pop the data from the stack)
     - else
       - skip = true
       - decrease left pointer by 1 (you can imagine its like pop the data from the stack)
       - break
   - if skip == false
     - change asteroids[left] to asteroids[right] (you can imagine its like push asteroids[i] into the stack)
     - increaes left pointer by 1
3. loop from index 0 until left pointer value
   - add asteroids[i] into the results
4. return the results 

Time Compleixty : O(N + M)
N -> size of asteroids
M -> left pointer value

Memory Complexity : O(1)

*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int left = 0;
        int right = 0;
        vector<int> results;

        while (right < asteroids.size()) {
            bool skip = false;

            while (left > 0 && asteroids[left - 1] > 0 && asteroids[right] < 0) {
                if (asteroids[left - 1] + asteroids[right] > 0) {
                    skip = true;
                    break;
                } else if (asteroids[left - 1] + asteroids[right] < 0) {
                    left--;
                } else {
                    skip = true;
                    left--;
                    break;
                }
            }

            if (skip == false) {
                // maintain the state
                asteroids[left] = asteroids[right];
                left++;
            }

            right++;
        }

        for (int i = 0; i < left; i++) {
            results.push_back(asteroids[i]);
        }

        return results;
    }
};