/*

How to solve the problem

# Using stack
1. initialize variables
   - stack<int> st
   - result = 0
   - multiply = 0
2. loop from first index of num until last index of num
   - number = num[i] - '0';
   - while stack.size() > 0 && stoi(stack.top() - '0') > number && k > 0
     - stack.pop()
     - k--
   - push the num[i] into the stack
3. if k > 0 && stack.size() > 0
   - stack.pop()
   - k--
4. while stack.size() > 0
   - result += stack.top()
   - stack.pop()
5. if result == ""
   - return "0"
6. reverse the result
7. remove the leading zeros from the string
8. if the pointer == result.length()
   - return "0", thats means all of the result string contain 0 number
9. return substr(index pointer position, result.length() - index pointer position)


Time Complexity : O(N + M + M)
N -> length of string num
M -> size of the stack

Memory Complexity : O(M)
M -> size of the stack

# Using two pointer

TODO : Write all the implementation

*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        int multiply = 0;
        int left = 0;
        string result = "";

        for(int i = 0; i < num.length(); i++) {
            int number = num[i] - '0';

            while (left > 0 && (num[left - 1] - '0') > number && k > 0) {
                left--;
                k--;
            }
            
            num[left] = num[i];
            left++;
        }

        while (k > 0 && left > 0) {
            left--;
            k--;
        }

        while (left > 0) {
            result += num[left - 1];
            left--;
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