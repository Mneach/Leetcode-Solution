class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
                
        int answer = 0;
        
        for(int i = 0; i < tickets.size(); i++){
            
            int decrement = 0;
            
            if(i > k) decrement = 1;
            
            answer += min(tickets[i], tickets[k] - decrement);
        }
        
        return answer;
    }
};