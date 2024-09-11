class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        string bitStart = "";
        string bitGoal = "";

        while(start > 0){
            bitStart += (start % 2) + '0';
            start /= 2;
        }

        while(goal > 0){
            bitGoal += (goal % 2) + '0';
            goal /= 2;
        }

        while(bitGoal.length() < bitStart.length()){
            bitGoal += '0';
        }

        while(bitStart.length() < bitGoal.length()){
            bitStart += '0';
        }
        
        reverse(bitStart.begin(), bitStart.end());
        reverse(bitGoal.begin(), bitGoal.end());

        int answer = 0;

        for(int i = 0; i < bitStart.length(); i++){
            if(bitStart[i] != bitGoal[i]){
                answer++;
            }
        }

        return answer;
    }
};