class Solution {
public:
    bool isPowerOfFour(int n) {
        
        long long int temp = 1;
        
        while(temp < n){
            temp *= 4;
        }
        
        return temp == n;
    }
};