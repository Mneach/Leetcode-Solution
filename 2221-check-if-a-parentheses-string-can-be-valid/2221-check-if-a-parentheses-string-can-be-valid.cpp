class Solution {
public:
    bool canBeValid(string s, string locked) {
        
        if(s.length() & 1) return false;
        
        int balance = 0;
        
        for(int i = 0; i < s.length(); i++){
            
            if(s[i] == '(' || locked[i] == '0') balance++;
            else balance--;
            
            if(balance < 0) return false;
        }
        
        balance = 0;
        
        for(int i = s.length() - 1; i >= 0; i--){
            if(s[i] == ')' || locked[i] == '0') balance++;
            else balance--;
            
            if(balance < 0) return false;
        }
        
        return true;
    }
};