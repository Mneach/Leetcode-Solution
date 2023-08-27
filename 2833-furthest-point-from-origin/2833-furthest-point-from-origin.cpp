class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        
        int answer = 0;
        int totalR = 0;
        int totalL = 0;
        int totalUndescore = 0;
        
        for(int i = 0; i < moves.length(); i++){
            if(moves[i] == 'L') totalL++;
            else if(moves[i] == 'R') totalR++;
            else totalUndescore++;
        }
        
        if(totalL == 0) answer = totalR + totalUndescore;
        else if(totalR == 0) answer = totalL + totalUndescore;
        else answer = abs(totalR - totalL) + totalUndescore;
        
        return answer;
    }
};