class Solution {
public:
    
    bool check(int number){
        
        bool valid = true;
        
        int temp = number;
        
        while(temp > 0){
            int digit = temp % 10;
            
            if(digit == 0) {
                valid = false;
                break;
            }
            
            if(number % digit != 0){
                valid = false;
                break;
            }
            
            temp /= 10;
        }
        
        return valid;
    }
    
    vector<int> selfDividingNumbers(int left, int right) {
        
        vector<int> answer;
        
        for(int i = left; i <= right; i++){
            if(check(i)){
                answer.push_back(i);
            }
        }
        
        return answer;
    }
};