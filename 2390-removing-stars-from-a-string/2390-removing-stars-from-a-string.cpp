class Solution {
public:
    string removeStars(string s) {
        stack<char> stack;
        string answer = "";
        
        for(int i = s.length() - 1; i >= 0; i--){
            
            if(s[i] != '*' && stack.empty() == false && stack.top() == '*'){
                stack.pop();
            }else{
                stack.push(s[i]);
            }
        }
        
        while(stack.empty() == false){
            answer += stack.top();
            stack.pop();
        }
        
        return answer;
    }
};