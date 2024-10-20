class Solution {
private:
    // Function to parse OR expressions
    bool evaluateOr(const vector<int>& res) {
        return accumulate(res.begin() + 1, res.end(), res[0], [](int a, int b) { return a | b; });
    }

    // Function to parse AND expressions
    bool evaluateAnd(const vector<int>& res) {
        return accumulate(res.begin() + 1, res.end(), res[0], [](int a, int b) { return a & b; });
    }

public:
    bool parseBoolExpr(const string& s) {
        stack<char> st;

        for (char ch : s) {
            if (ch == ',' || ch == '(') continue;

            if (ch == ')') {
                vector<int> res;
                // Collect the results until we encounter an operator
                while (st.top() != '&' && st.top() != '|' && st.top() != '!') {
                    res.push_back(st.top() == 't' ? 1 : 0);
                    st.pop();
                }

                char op = st.top(); // Get the operator
                st.pop();

                bool evalRes = false;
                if (op == '&') evalRes = evaluateAnd(res);
                else if (op == '|') evalRes = evaluateOr(res);
                else if (op == '!') evalRes = !res[0];

                st.push(evalRes ? 't' : 'f');
            } else {
                st.push(ch);
            }
        }

        return st.top() == 't';
    }
};
