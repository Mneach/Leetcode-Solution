class Solution {
public:
    int passThePillow(int n, int time) {
        int start = 1;
        bool increment = true;

        while(time > 0){
            
            if(start == n) increment = false;
            else if (start <= 1) increment = true;

            if(increment){
                start++;
            }else{
                start--;
            }

            time--;
        }

        return start;
    }
};