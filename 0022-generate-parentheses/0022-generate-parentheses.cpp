class Solution {
public:
    
    void recursive(vector<string> &answer, int total, string s, int maxTotal){
        if(maxTotal == total){
            int totalCompleteBracket = 0;
            int totalLeftBracket = 0;
            int totalRightBracket = 0;
            
            bool valid = true;
            
            for(int i = 0; i < s.length(); i++){
                if(s[i] == ')' && totalLeftBracket == 0){
                    valid = false;
                    break;
                }else if(s[i] == '('){
                    totalLeftBracket++;
                }else if(s[i] == ')'){
                    totalRightBracket++;
                    
                    if(totalLeftBracket == totalRightBracket){
                        totalCompleteBracket += totalLeftBracket;
                        totalLeftBracket = 0;
                        totalRightBracket = 0;
                    }
                }
            }
            
            if(totalCompleteBracket == maxTotal / 2){
                answer.push_back(s);
            }
        }else{
            string openBracket = s + "(";
            string closeBracket = s + ")";
            recursive(answer, total + 1, openBracket, maxTotal);
            recursive(answer, total + 1, closeBracket, maxTotal);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        
        recursive(answer, 0, "", n * 2);
        
        return answer;
    }
};