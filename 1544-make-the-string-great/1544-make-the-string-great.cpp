class Solution {
public:
    string makeGood(string s) {
        
        string answer = "";
        
        for(auto data : s){
            
            if(answer == "") {
                answer += data;
            }else{
                if(answer[answer.size() - 1] == data){
                    answer += data;
                }else if(tolower(answer[answer.size() - 1]) == tolower(data)){
                    answer.pop_back();
                }else{
                    answer += data;
                }                
            }

        }
        
        return answer;
    }
};