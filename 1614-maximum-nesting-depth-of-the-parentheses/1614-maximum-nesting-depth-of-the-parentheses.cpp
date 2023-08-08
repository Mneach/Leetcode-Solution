class Solution {
public:
    int maxDepth(string s) {
        
        stack<char> st;
        
        int answer = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(') st.push('(');
            else if(s[i] == ')' && st.size() != 0){
                if(st.size() > answer) answer = st.size();
                st.pop();
            } 
        }
        
        if(st.size() > answer) answer = st.size();
        
        return answer;
    }
};