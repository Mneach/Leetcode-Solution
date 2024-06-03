class Solution {
public:
    int mirrorReflection(int p, int q) {

        if(p == q) return 1;
        
        int x , y;
        x = y = 1;

        while(x * p != y * q){
            y++;
            x = y * q / p;
        }

        int answer = 0;
        if(x % 2 == 1 and y % 2 == 1) {
            answer = 1;
        }else if(x % 2 == 1 && y % 2 == 0){
            answer = 2;
        }

        return answer;
    }
};