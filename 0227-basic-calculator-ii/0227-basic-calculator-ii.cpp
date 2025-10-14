/*

How to solve the problem

Process rank : 
1. multipication
2. division
3. substraction
4. addition

# Using stack
1. initialize variables
   - stack<string> st
   - result = 0
   - index = 0
2. loop for every character in string s
   - if s[index] == ' '
     - continue;
   - else s[index] is a number
     - number = extractNumber(s, index)
     - if st.size() > 1 && (st.top() == '/' || st.top() == '*')
       - operator = st.top()
       - st.pop()
       - prevNumber = st.top()
       - st.pop()
       - if operator == '/'
         - number = prevNumber / number
       - else 
         - number = prevNumber * number
     - push number to the stack
     - operator = extractOperator(s, index)
     - if operator != ""
       - push operator into the stack
3. while stack.size() > 2 
   - firstNumber = st.top()
   - st.pop()
   - operator = st.top()
   - st.pop()
   - secondNumber = st.top()
   - if opeator == '+'
     - firstNumber += secondNumber
   - else
     - firstNumber -=  secondNumber
   - push first number into the stack
4. return st.top()

Time Complexity : O(N + M)
N -> length of string s
M -> size of stack

Memory Compelxity : O(M)
M -> size of stack

*/

class Solution {
private:
    string extractNumber(string &s, int &index) {
        string result = "";

        while (index < s.length() && s[index] >= '0' && s[index] <= '9') {
            result += s[index];
            index++;
        }

        return result;
    }

    string extractOperator(string &s, int &index) {

        while (index < s.length() && s[index] == ' ') {
            index++;
        }

        if (index == s.length()) {
            return "";
        }

        string result = "";
        result += s[index];
        index++;

        return result;
    }
public:
    int calculate(string s) {
        stack<string> st;
        int index = 0;

        while (index < s.length()) {
            if (s[index] >= '0' || s[index] == '9') {
                string number = extractNumber(s, index);
                string currentOperator = extractOperator(s, index);

                if (st.size() > 1 && (st.top() == "*" || st.top() == "/")) {
                    string prevOperator = st.top(); st.pop();
                    int result = stoi(st.top()); st.pop();

                    if (prevOperator == "*") {
                        result *= stoi(number);
                    } else {
                        result /= stoi(number);
                    }

                    st.push(to_string(result));
                } else {
                    st.push(number);
                }

                if (currentOperator.length() > 0) {
                    st.push(currentOperator);
                }

            } else {
                index++;
            }
        }

        stack<string> bucket;

        while (st.size() > 0) {
            bucket.push(st.top());
            st.pop();
        }

        while (bucket.size() > 2) {
            int firstNumber = stoi(bucket.top()); bucket.pop();
            string currentOperator = bucket.top(); bucket.pop();
            int secondNumber = stoi(bucket.top()); bucket.pop();

            if (currentOperator == "+") {
               firstNumber += secondNumber;
            } else {
               firstNumber -= secondNumber;
            }

            bucket.push(to_string(firstNumber));
        }

        return stoi(bucket.top());
    }
};