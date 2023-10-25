class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int answer = 0;
        int minimum = INT_MAX;
        
        
        for(int i = 0 ; i < prices.size(); i++){
            
            if(prices[i] <= minimum){
                minimum = prices[i];
            }else{
                answer = max(prices[i] - minimum, answer);
            }
        }
        
        return answer;
    }
};