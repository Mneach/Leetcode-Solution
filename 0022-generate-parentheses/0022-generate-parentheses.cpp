/*

How to solve the problem

# Using recursive
1. void recursive functions (int n, string current, open bracket, close bracket, result)
   - if current.length() == n * 2
     - if current is valid answer, then push current to result
   - else if open bracket > n
     - return
   - else if close brakcet > open bracket
     - return
   - choose open bracket
     - recursive (n, current + '(', open bracket + 1, close bracket + 1)
   - choose close bracket
     - recursive (n, current + '(', open bracket + 1, close bracket + 1)
2. initialize variables
   - vector<string> results
3. call recrusive(n, "", 0, 0, results)
4. return results

Time Complexity : O(2^(N * 2) * (N * 2)) = O(2^N)
N -> pairs of parentheses

Memory Complexity : O(2^N * N) = O(2^N)
N -> pairs of parentheses

*/

class Solution {
private:
    void recursive(int n, string current, int openBracket, int closeBracket, vector<string> &results) {
        if (current.length() == n * 2) {
            stack<char> stack;

            for (int i = 0; i < current.length(); i++) {
                if (stack.empty()) {
                    stack.push(current[i]);
                } else if (stack.top() == '(' && current[i] == ')') {
                    stack.pop();
                } else {
                    stack.push(current[i]);
                }
            }

            if (stack.empty()) {
                results.push_back(current);
            }
        } else if (openBracket > n) {
            return;
        } else if (closeBracket > openBracket) {
            return;
        }

        // choose open bracket
        current += "(";
        recursive(n, current, openBracket + 1, closeBracket, results);
        current.pop_back();

        // choose close bracket
        current += ")";
        recursive(n, current, openBracket, closeBracket + 1, results);
        current.pop_back();
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> results;        

        recursive(n, "(", 1, 0, results);

        return results;
    }
};