class Solution {
public:
    int minLength(string s) {
        
        string answer = s;
        
        
        while(true){
            bool check = false;    
            
            int length = answer.length();
            for(int i = 0; i < length - 1; i++){
                if((answer[i] == 'A' && answer[i + 1] == 'B') || answer[i] == 'C' && answer[i + 1] == 'D'){
                    if(i == 0) answer = answer.substr(i + 2, answer.length());
                    else answer = answer.substr(0 , i) + answer.substr(i + 2 , answer.length());
                    check = true;
                    break;
                }else {
                    check = false;
                }
            }
            
            if(!check) break;
        }
        
        return answer.length();
    }
};