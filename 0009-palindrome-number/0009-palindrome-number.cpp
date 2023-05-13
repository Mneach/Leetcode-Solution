class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0) return false;
        
        string s;
        
        while(x > 0){
            s.push_back((x % 10) + '0');
            x /= 10;
        }
        
        string temp = s;
        reverse(temp.begin(), temp.end());
        
        return s == temp;
    }
};