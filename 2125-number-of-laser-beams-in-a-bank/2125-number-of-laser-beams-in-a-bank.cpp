class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int answer = 0;
        int prev = -1;
        for(int i = 0; i < bank.size(); i++){
            int totalLaserBeam = 0;
            
            for(int j = 0; j < bank[i].length(); j++){
                if(bank[i][j] == '1'){
                    totalLaserBeam++;
                }
            }
            
            if(totalLaserBeam > 0){
                if(prev != -1){
                    answer += (prev * totalLaserBeam);
                }
                
                prev = totalLaserBeam;
            }
        }
        
        return answer;
    }
};