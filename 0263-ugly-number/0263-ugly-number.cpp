class Solution {
public:
    
    bool isPrime(long long int number){
        bool valid = true;
        
        if(number == 1) return false;
        
        for(long long int i = 2; i * i <= number; i++){
            if(number % i == 0) return false;
        }
        
        return true;
    }
    
    bool limited(long long int number){
        return number != 2 && number != 3 && number != 5;
    }
    
    bool isUgly(int n) {
        
        if(n == 1) return true;
        if(n <= 0) return false;
        
        for(long long int i = 1; i * i <= n; i++){
            if(n % i == 0){
                long long int firstNumber = i;
                long long int secondNumber = n / i;
                
                if(limited(firstNumber) && isPrime(firstNumber)){
                    return false;
                }else if(limited(secondNumber) && isPrime(secondNumber)){
                    return false;
                }
            }
        }
        
        return true;
    }
};