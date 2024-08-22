class Solution {
public:
    int findComplement(int num) {
        int point = 0;
        int answer = 0;

        while(num > 0){
            if(num % 2 == 0){
                answer += pow(2, point);
                num /= 2;
            }else if(num == 1){
                
                num--;
            }else{
               num /= 2;
            }

            point++;
        }

        return answer;
    }
};