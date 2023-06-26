class Solution {
public:
    string decodeString(string s) {
        stack<int> arrInt;
        stack<string> arrStr;
        
        string answer = "";
        
        int i = 0;
        int openBracket = 0;
        
        while(i < s.length()){
            if(s[i] >= '0' && s[i] <= '9'){
                string temp = "";
                while(i < s.length() && s[i] >= '0' && s[i] <= '9'){
                    temp += s[i];
                    i++;
                }  
               
                arrInt.push(stoi(temp));
            }

            if(s[i] == '['){
                openBracket++;
                if(i != 0 && s[i - 1] != ']') i++;
            
                string temp = "";
                while(i < s.length() && s[i] >= 'a' && s[i] <='z'){
                    temp += s[i];
                    i++;
                }
                if(s[i] != '[') arrStr.push(temp);
            }
          
            if(s[i] == ']'){
                openBracket--;
                string temp = "";
                i++;
                if(arrInt.size() > 1){
                    for(int j = 0; j < arrInt.top(); j++){
                        temp += arrStr.top();
                    }
                     
                    arrInt.pop();
                    arrStr.pop();
                    
                    if(arrStr.top() != "") temp = arrStr.top() + temp;
                    arrStr.pop();
                    
                    while(i < s.length() && s[i] >= 'a' && s[i] <='z') {
                        temp += s[i];
                        i++;
                    }       
                    
                    arrStr.push(temp);
                }else{
                   
                    for(int j = 0; j < arrInt.top(); j++){
                        temp += arrStr.top();
                    }
                    
                    arrInt.pop();
                    arrStr.pop();
                    
                    answer += temp;
                    
                    while(i < s.length() && s[i] >= 'a' && s[i] <='z') {
                        answer += s[i];
                        i++;
                    }
                }
            }
            
            if(openBracket == 0 && s[i] >= 'a' && s[i] <='z'){
                answer += s[i];
                i++;
            }
           
        }
        
        
        return answer;
    }
};