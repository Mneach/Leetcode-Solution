/*

How to solve the problem

# Using stack
1. initialize variables
   - stack<int> st
   - result = 0
   - multiply = 0
2. loop from first index of num until last index of num
   - number = num[i] - '0';
   - if st.size() == 0
     - push number into the stack
   - else if stack.top() < number && k > 0
     - stack.pop()
     - k--
3. while (k > 0 && staci.size() > 0) 
   - stack.pop()
   - k--
4. to get the result
   - result += (number * pow(10, multiply))
   - increaes multiply by 1
5. change the result to the string (return to_string(result))

Time Complexity : O(N + M + M)
N -> length of string num
M -> size of the stack

Memory Complexity : O(M)
M -> size of the stack
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        int multiply = 0;
        string result = "";
        stack<char> st;

        for(int i = 0; i < num.length(); i++) {
            int number = num[i] - '0';

            while (st.size() > 0 && (st.top() - '0') > number && k > 0) {
                st.pop();
                k--;
            }

            st.push(num[i]);
        }

        while (k > 0 && st.size() > 0) {
            st.pop();
            k--;
        }

        while (st.size() > 0) {
            result += st.top();
            st.pop();
        }

        if (result == "") {
            return "0";
        }

        reverse(result.begin(), result.end());

        // remove leadings zero from string
        int resultIndex = 0;

        while (resultIndex < result.length() && result[resultIndex] == '0') {
            resultIndex++;
        }

        if (resultIndex == result.length()) {
            return "0";
        }

        return result.substr(resultIndex, result.length() - resultIndex);
    }
};