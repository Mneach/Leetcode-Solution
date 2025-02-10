class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;

        for (auto c : s) {
            bool isDigit = c >= '0' && c <= '9';
            if (st.size() > 0 && isDigit) {
                st.pop();
            } else if (isDigit == false) {
                st.push(c);
            }
        }

        string answer = "";
        while(st.size() > 0) {
            answer += st.top();
            st.pop();
        }

        reverse(answer.begin(), answer.end());

        return answer;
    }
};