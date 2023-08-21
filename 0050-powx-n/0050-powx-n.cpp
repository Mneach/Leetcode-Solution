class Solution {
public:
    double myPow(double x, int n) {
        long long int exponen = abs(n);
        double result = pow(x, exponen);
        
        if(n < 0){
            result = 1 / result;
        }
        
        return result;
    }
};