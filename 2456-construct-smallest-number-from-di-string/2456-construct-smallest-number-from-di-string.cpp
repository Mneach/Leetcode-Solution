class Solution {
public:
    string smallestNumber(string pattern) {
        string answer = "";
        stack<int> st;
        
        for (int i = 0; i <= pattern.size(); i++) {
            st.push(i + 1);

            if (i == pattern.size() || pattern[i] == 'I') {
                // reset the state
                
                while (st.size() > 0) {
                    char number = st.top() + '0';
                    st.pop();
                    answer += number;
                }
            }
        }

        return answer;
    }
};