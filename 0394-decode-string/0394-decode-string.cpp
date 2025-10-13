/*

How to solve the problem

# Using stack
1. initialize variables
   - stack<string> st
   - result = ""
2. loop from the first index of string until last index of string
   - if current character is a letter
     - extract the word
     - push that word into the stack
   - else if current character is a number
     - extract the number
     - push into the stack
     - increase the index value by 1
   - else if current charcter is a close bracket
     - while stack.size() > 1
        - get the first data and second data
          - if second data is not a number
          - combine first data with the second data
          - push that data into the stack
        - else
          - duplicate the first data equal to the second data value
          - break the loop
       - increase index value by 1
3. get all of the data from stack
    - if stack.size() == 1
      - add result by stack.top()
    - get the first data and second data
    - if second data is not a number
       - combine first data with the second data
     - else
       - duplicate the first data equal to the second data value
    - push the new combined data into the stack
      - the reason is because of need to combine the data to get the result
5. return the result

Time Complexity : O(N - total open and close bracket in string s) -> O(N)
N -> length of s

Memory complexity : (M)
M -> size of stack

*/

class Solution {
private:

    string getWord(string &s, int &index) {
        string result = "";

        while (index < s.length() && s[index] != ']' && isDigit(s[index]) == false) {
            result += s[index];
            index++;
        }

        return result;
    }

    string getDigit(string &s, int &index) {
        string result = "";
        
        while (index < s.length() && s[index] != '[' && isDigit(s[index])) {
            result += s[index];
            index++;
        }

        return result;
    }

    bool isLetter(char x) {
        return x >= 'a' && x <= 'z';
    }

    bool isDigit(char x) {
        return x >= '0' && x <= '9';
    }
public:
    string decodeString(string s) {
        stack<string> st;
        string result = "";

        int index = 0;
        while (index < s.length()) {
            if (isLetter(s[index])) {
                string word = getWord(s, index);
                st.push(word);
            } else if (isDigit(s[index])) {
                string digit = getDigit(s, index);
                st.push(digit);
            } else if (s[index] == ']') {
                while (st.size() > 1) {
                    string temp = "";
                    string firstData = st.top(); st.pop();
                    string secondData = st.top(); st.pop();
                        
                    if (isDigit(secondData[0])) {
                        int loop = stoi(secondData);

                        while (loop > 0) {
                            temp += firstData;
                            loop--;
                        }

                        st.push(temp);
                        break;
                    } else {
                        temp += secondData;
                        temp += firstData;
                        st.push(temp);
                    }
                }

                index++;
            } else if (s[index] == '[') {
                index++;
            }
        }

        while (st.size() > 0) {

            if (st.size() == 1) {
                result += st.top();
                break;
            }

            string temp = "";
            string firstData = st.top(); st.pop();
            string secondData = st.top(); st.pop();

            if (isDigit(secondData[0])) {
                int loop = stoi(secondData);
                while (loop > 0) {
                    temp += firstData;
                    loop--;
                }
            } else {
                temp += secondData;
                temp += firstData;
            }

            st.push(temp);
        }

        return result;
    }
};