class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> x;
        stack<char> y;
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '#'  && x.empty() == false) x.pop();
            else x.push(s[i]);
        }
        
        for(int i = 0; i < t.length(); i++){
            if(t[i] == '#' && y.empty() == false) y.pop();
            else y.push(t[i]);            
        }
        
        string resultX = "";
        string resultY = "";
        
        while(x.empty() == false) {
            if(x.top() != '#') resultX += x.top();
            x.pop();
        }
        
        while(y.empty() == false){
            if(y.top() != '#') resultY += y.top();
            y.pop();
        }
        
        return resultX == resultY;
    }
};