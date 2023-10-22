class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        
        string first = "qwertyuiop";
        string second = "asdfghjkl";
        string third = "zxcvbnm";
        
        vector<string> answer;
        for(int i = 0; i < words.size(); i++){
            
            string find = "";
            bool valid = true;
            for(int j = 0; j < words[i].size(); j++){
                
                int firstFind = first.find(tolower(words[i][j]));
                int secondFind = second.find(tolower(words[i][j]));
                int thirdFind = third.find(tolower(words[i][j]));
                
                if(find == ""){
                    if(firstFind != -1) find = "first";
                    else if(secondFind != -1) find = "second";
                    else find = "third";
                }else{
                    if((firstFind != -1 && find == "first") || (secondFind != -1 && find == "second") || (thirdFind != -1 && find == "third")){
                        valid = true;
                    }else{
                        valid = false;
                        break;
                    }
                }
            }
            
            if(valid) answer.push_back(words[i]);
        }
        
        return answer;
    }
};