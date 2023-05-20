class Solution {
public:
    string reverseWords(string s) {
        
        bool checkSpace = false;
        
        vector<string> vs;
        
        string temp = "";
        for(int i = 0; i < s.length(); i++){
            
            if(isalnum(s[i])){
                temp.push_back(s[i]);
                checkSpace = true;
            }else if(checkSpace == true){
                vs.push_back(temp);
                temp = "";
                checkSpace = false;
            }
        }
        
        if(temp != ""){
            vs.push_back(temp);
        } 
        
        string answer = "";
        for(int i = vs.size() - 1; i >= 0; i--){
            if(i != 0) answer += vs[i] + ' ';
            else answer += vs[i];
        }
        
        return answer;
    }
};