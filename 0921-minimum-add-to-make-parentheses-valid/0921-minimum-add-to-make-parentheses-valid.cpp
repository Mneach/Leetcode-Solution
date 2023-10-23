class Solution {
public:
    int minAddToMakeValid(string s) {
        
        stack<char> sc;
        
        for(int i = 0; i < s.length(); i++){
            if(sc.empty()){
                sc.push(s[i]);
            }else if(s[i] == ')' && sc.top() == '('){
               sc.pop();
            }else{
                sc.push(s[i]);
            }
        }
        
        return sc.size();
    }
};