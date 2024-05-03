class Solution {
public:
    
    void getVersion(string version, vector<string> &s){
        string temp = "";
        bool startWithZero = false;
        for(int i = 0; i < version.length(); i++){
            char x = version[i];
            
            if(x == '.'){
                s.push_back(temp);
                temp = "";
            }else{
                if(temp == "" && x == '0'){
                    temp = x;
                    startWithZero = true;
                }else if(startWithZero && x != '0'){
                    temp = x;
                    startWithZero = false;
                }else{
                    temp += x;
                }
            }
        }     
        
        if(temp != ""){
            s.push_back(temp);
        }
    }
    
    int compareVersion(string version1, string version2) {
        
        vector<string> s1;
        vector<string> s2;
        
        getVersion(version1, s1);
        getVersion(version2, s2);
        
        if(s1.size() < s2.size()){
            
            int index = 0;
            for(int i = 0; i < s1.size(); i++){
                int temp1 = stoi(s1[i]);
                int temp2 = stoi(s2[i]);
                
                if(temp1 < temp2){
                    return -1;
                }else if(temp1 > temp2){
                    return 1;
                }
                
                index++;
            }
            
            for(int i = index; i < s2.size(); i++){
                int temp2 = stoi(s2[i]);
                
                if(temp2 != 0){
                    return -1;
                }
            }
            
            return 0;
        }else if(s1.size() > s2.size()){
            int index = 0;
            for(int i = 0; i < s2.size(); i++){
                int temp1 = stoi(s1[i]);
                int temp2 = stoi(s2[i]);
                
                if(temp1 < temp2){
                    return -1;
                }else if(temp1 > temp2){
                    return 1;
                }
                index++;
            }
            
            for(int i = index; i < s1.size(); i++){
                int temp1 = stoi(s1[i]);
                
                if(temp1 != 0){
                    return 1;
                }
            }
            
            return 0;
        }else{
            for(int i = 0; i < s1.size(); i++){
                int temp1 = stoi(s1[i]);
                int temp2 = stoi(s2[i]);
                
                if(temp1 < temp2){
                    return -1;
                }else if(temp1 > temp2){
                    return 1;
                }
            }
            
            return 0;
        }
    }
};