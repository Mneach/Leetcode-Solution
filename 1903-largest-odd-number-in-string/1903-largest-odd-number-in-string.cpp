class Solution {
public:
    string largestOddNumber(string num) {
        
        int i = num.size() - 1;
        
        while(i >= 0){
            
            int number = num[i] - '0';
            
            if(number % 2 == 1){
                break;
            }
            
            i--;
        }
        
        if(i >= 0) return num.substr(0, i + 1);
        return "";
    }
};