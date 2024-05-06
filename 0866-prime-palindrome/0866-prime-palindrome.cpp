class Solution {
public:
    
    bool valid(int number, int n){
        
        if(number <= 1) return false;
        
        bool res = true;
        
        for(int i = 2; i * i <= number; i++){
            if(number % i == 0) res = false;
        }
        
        return res && number >= n;
    }
    
    string reverse(string x){
        string res = "";
        
        for(int i = x.length() - 1; i >= 0; i--){
            res += x[i];
        }
        
        return res;
    }
    
    int primePalindrome(int n) {
        if(n >= 8 && n <= 11){
            return 11;
        }else{
            for(int i = 1; i < 100000; i++){
                string x = to_string(i);
                string reverseX = reverse(x);
                int number = stoi(x + reverseX.substr(1));
                
                if(valid(number, n)){
                    return number;
                }
            }
        }
        
        return -1;
    }
};