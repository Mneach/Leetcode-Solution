class Solution {
public:
    string smallestString(string s) {
        bool hasChange = false;
        
        if(s[0] != 'a'){
            for(int j = 0; j < s.length(); j++){
                if(s[j] == 'a') break;
                else s[j] = s[j] - 1;
            }
            hasChange = true;
            
        }else{
            bool change = false;
            for(int i = 0; i < s.length(); i++){    
                if(s[i] == 'a'){
                    change = true;
                }else if(change){
                    for(int j = i; j < s.length(); j++){
                        if(s[j] == 'a') {                            
                            break;
                        }else{
                            s[j] = s[j] - 1;
                        }
                    }
                    hasChange = true;
                }
                
                if(hasChange) break;
            }        
        }
            
        if(!hasChange){
            s[s.length() - 1] = 'z';
        }
        return s;
    }
};