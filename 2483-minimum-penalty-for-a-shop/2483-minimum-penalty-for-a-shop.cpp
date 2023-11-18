class Solution {
public:
    int bestClosingTime(string customers) {
            
        if(customers.length() == 1){
            if(customers[0] == 'N'){
                return 0;
            }else{
                return 1;
            }
        } 
        
        int answer = 0;
        int minimumPenalty = INT_MAX;
        int totalPenalty = 0;
        
        for(int i = 0; i < customers.length(); i++){
           if(customers[i] == 'Y') totalPenalty++;
        }
        
        if(totalPenalty < minimumPenalty){
             answer = 0;
             minimumPenalty = totalPenalty;
        }
        
        for(int i = 0; i < customers.length(); i++){
            
            if(customers[i] == 'Y'){
                totalPenalty--;
            }else if(customers[i] == 'N'){
                totalPenalty++;
            }
            
            //cout << totalPenalty << endl;
            
            if(totalPenalty < minimumPenalty){
                answer = i + 1;
                minimumPenalty = totalPenalty;
            }
        }
        
        
        return answer;
    }
};