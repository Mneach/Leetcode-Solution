class Solution {
public:
    int mySqrt(int x) {
        
        int answer = 0;
        for(long long int i = 0; i <= x; i++){
            if(i * i == x){
                answer = i;
                break;
            }else if(i * i > x){
                answer = i - 1;
                break;
            }
        }
        
        return answer;
    }
};