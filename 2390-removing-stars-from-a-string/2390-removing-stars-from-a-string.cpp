class Solution {
public:
    string removeStars(string s) {
        stack<char> stack;
        string answer = "";
        
        for(int i = 0; i < s.length(); i++){
            
            if(s[i] == '*'){
                stack.pop();
            }else{
                stack.push(s[i]);
            }
        }
        
        while(stack.empty() == false){
            answer += stack.top();
            stack.pop();
        }
        
        reverse(answer.begin(), answer.end());
        
        return answer;
    }
};