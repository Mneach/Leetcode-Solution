class Solution {
public:
    
    int sum(int n){
        return (n * (n + 1)) / 2;
    }
    
    int totalMoney(int n) {
        
        if(n <= 7){
            return sum(n);
        }else{
            int temp = sum(7);
            int answer = temp;
            int decrement = 1;
            int increment = 8;
            int start = 2;
            n -= 7;
            
            while(n > 7){
                temp = (temp + increment) - decrement;
                answer += temp;
                n -= 7;
                increment++;
                decrement++;
                start++;
            }
            
            while(n > 0){
                answer += start;
                n--;
                start++;
            }
            
            return answer;
        }
        
    }
};