class Solution {
public:
    string reverseParentheses(string s) {
        
        stack<int> currentLeftPosition;
        
        string temp = "";
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] >= 'a' && s[i] <= 'z') temp += s[i];
        }
        
        int rightPointer = 0;
        for(int i = 0; i < s.length(); i++){
            
            if(s[i] == '('){
               currentLeftPosition.push(rightPointer); 
            }else if(s[i] == ')'){
                int leftPointer = currentLeftPosition.top();
                currentLeftPosition.pop();
                
                reverse(temp.begin() + leftPointer, temp.begin() + rightPointer);
            }else{
                rightPointer++;
            }
        }
        
        return temp;
    }
};