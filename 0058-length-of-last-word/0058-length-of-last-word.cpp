class Solution {
public:
    int lengthOfLastWord(string s) {
        
        
       bool checkSpace = false;
       string answer = "";
        
       for(int i = s.length() - 1; i >= 0; i--){
           
           
          if(s[i] == ' ' && answer != ""){
              break;
          }else if(tolower(s[i]) >= 'a' && tolower(s[i]) <= 'z'){
              answer += s[i];
          }
       }
        
       return answer.size();
    }
};