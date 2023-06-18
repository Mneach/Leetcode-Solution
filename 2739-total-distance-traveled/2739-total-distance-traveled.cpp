class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int result = mainTank;
        
        for(int i = 5; i <= mainTank; i += 5){
            mainTank++;
            additionalTank--;
            
            if(additionalTank == 0) break;
        }
        
        return mainTank * 10;
    }
};