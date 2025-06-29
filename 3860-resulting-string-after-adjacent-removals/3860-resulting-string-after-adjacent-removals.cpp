class Solution {
public:
    string resultingString(string s) {
        string answer = "";
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            if (st.size() == 0) {
                st.push(s[i]);
            } else {
                char last = st.top();
                int current = last - 'a';
                int next = s[i] - 'a';

                if ((current == 0 && next == 25) || (current == 25 && next == 0)) {
                    st.pop();
                } else if (abs(current - next) == 1) {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
        }

        while(st.size() > 0) {
            answer += st.top();
            st.pop();
        }

        reverse(answer.begin(), answer.end());

        return answer;
    }
};