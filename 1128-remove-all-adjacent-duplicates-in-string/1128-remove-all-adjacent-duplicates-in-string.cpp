class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;

        for (auto c : s) {
            if (st.size() == 0) st.push(c);
            else if (st.top() == c) st.pop();
            else st.push(c);
        }

        string answer = "";
        while(st.size() > 0) {
            char data = st.top();
            answer += data;
            st.pop();
        }

        reverse(answer.begin(), answer.end());
        return answer;
    }
};