
/*

How to solve the problem

# Using stack
1. initialize variables
   - stack<string> stack
   - string result
2. loop from first index of path until last index of path
   - take word from path
   - if word == ".", then continue to the next word
   - else if word == ".." && stack.size() > 0, then pop the data from stack
   - else if word != ".."
     - push the word into the stack
3. to construct the result we can use another stack
4. move all of data from the current stack to another stack
5. loop for every data in another stack
   - result += "/"
   - result += anotherStack.top()
   - result.pop()
6. return the result

Time Complexity : O(N + M + M)
N -> length of string s
M -> size of stack

Memory Complexity : O(M + M)
M -> size of stack

*/

class Solution {
private:
    string getWord(string &path, int &index) {
        string result = ""; 
        bool start = false;

        while (index < path.length()) {
            if (path[index] == '/') {

                if (start == true && result != "") {
                   return result;
                }

                start = true;
            } else {
                result += path[index];
            }

            index++;
        }

        return result;
    }
public:
    string simplifyPath(string path) {
        string result = "";
        stack<string> st;

        int index = 0;
        while (index < path.length()) {
            string word = getWord(path, index);
            
            if (word == "." || word == "") {
                continue;
            } else if (word == ".." && st.size() > 0) {
                st.pop();
            } else if (word != "..") {
                st.push(word);
            }
        }

        if (st.empty()) {
            return "/";
        }

        stack<string> bucket;
        while (st.size() > 0) {
            bucket.push(st.top());
            st.pop();
        }

        while (bucket.size() > 0) {
            result += "/";
            result += bucket.top();
            bucket.pop();
        }

        return result;
    }
};