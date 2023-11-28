class Solution {
public:
    
    
    double myPow(double x, int n) {
       
        if(n == 0) return 1;
        else if(n == -1) return 1/x;
        
        double temp = myPow(x, n / 2);
        cout << temp << endl;
        if(n % 2 == 0){
            return (temp * temp);
        }else if(n % 2 == 1){
            return (x * temp * temp);
        }else{
            return (temp * temp * (1 / x));
        }
    }
};