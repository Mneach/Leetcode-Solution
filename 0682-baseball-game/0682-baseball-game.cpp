/*

How to solve the problem

# Main Idea
1. Instead of using stack to maintaint the state, we can utilize two pointer to maintaint the state.

# Using two pointer
1. initialize variables
   - left = 0
   - right = 0
   - result = 0
2. while right < operations.size()
   - if operations[right] == "D"
     - prev = stoi(operations[left - 1])
     - operations[left] = to_string(prev)
     - left++
   - else if operations[right] == "C"
     - left--
   - else if operations[right] == "+"
     - firstPrev = stoi(operations[left - 1])
     - secondPrev = stoi(operations[left - 2])
     - operations[left] = to_string(firstPrev + secondPrev)
     - left++
   - else
     - change operations[left] to operations[rigth]
     - increaes the left pointer
   - increase the right pointer
3. To get the result we need to loop from index 0 until index left
   - change operations[i] to int
   - add that value into the result value
4. return the result

Time Complexity : O(N + M)
N -> size of opeartions array
M -> left pointer value

Memory Complexity : O(1)

*/

class Solution {
public:
    int calPoints(vector<string>& operations) {
        int result = 0;
        int left = 0;
        int right = 0;

        while (right < operations.size()) {
            if (operations[right] == "D") {
                int prev = stoi(operations[left - 1]);
                operations[left] = to_string(prev * 2);
                left++;
            } else if (operations[right] == "C") {
                left--;
            } else if (operations[right] == "+") {
                int firstPrev = stoi(operations[left - 1]);
                int secondPrev = stoi(operations[left - 2]);
                operations[left] = to_string(firstPrev + secondPrev);
                left++;
            } else {
                operations[left] = operations[right];
                left++;
            }

            right++;
        }

        for (int i = 0; i < left; i++) {
            result += stoi(operations[i]);
        }

        return result;
    }
};