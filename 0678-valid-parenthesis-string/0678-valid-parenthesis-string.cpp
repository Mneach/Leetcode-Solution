class Solution {
public:
    bool checkValidString(string s) {
       
        int balance = 0;
        
        for(int i = 0; i < s.length(); i++){
            
            if(s[i] == '(' || s[i] == '*'){
                balance++;
            }else{
                balance--;
            }
            
            if(balance < 0) return false;
        }
        
        balance = 0;
        for(int i = s.length() - 1; i >= 0; i--){
            
            if(s[i] == ')' || s[i] == '*'){
                balance++;
            }else{
                balance--;
            }
            
            if(balance < 0) return false;
        }      
        
        return true;
    }
};