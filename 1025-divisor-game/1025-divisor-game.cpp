class Solution {
public:
    bool divisorGame(int n) {
        
        if(n == 1) return false;
        else if(n % 2 == 0) return true;
        else return false;
    }
};