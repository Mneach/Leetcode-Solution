class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        
        string temp = "[({";
        
        for(int i = 0; i < s.length(); i++){
            
            if(s[i] == ')' && st.empty() == false && st.top() == '('){
                st.pop();
            }else if(s[i] == ']' && st.empty() == false && st.top() == '['){
                st.pop();
            }else if(s[i] == '}' && st.empty() == false && st.top() == '{'){
                st.pop();
            }else{
                st.push(s[i]);
            }
            
        }
        
        return st.empty();
    }
};