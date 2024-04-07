class Solution {
public:
    bool checkValidString(string s) {
       
        stack<int> openBracket;
        stack<int> asterix;
        
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            
            if(ch == '('){
                openBracket.push(i);
            }else if(ch == '*'){
                asterix.push(i);
            }else{
                
                if(openBracket.empty() == false){
                    openBracket.pop();
                }else if(asterix.empty() == false){
                    asterix.pop();
                }else{
                    return false;
                }
            }
        }
        
        while(openBracket.empty() == false && asterix.empty() == false){
            if(openBracket.top() > asterix.top()){
                return false;
            }
            
            asterix.pop();
            openBracket.pop();
        }
        
        return openBracket.empty();
    }
};