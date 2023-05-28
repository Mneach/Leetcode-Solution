class Solution {
public:
    string removeTrailingZeros(string num) {
        
        string answer;
        bool check = false;
        
        for(int i = num.length() - 1; i >= 0; i--){
            
            if(num[i] != '0' && !check){
                check = true;
            }
            
            if(check){
                answer.push_back(num[i]);
            }
        }
        
        reverse(answer.begin(), answer.end());
        
        return answer;
    }
};