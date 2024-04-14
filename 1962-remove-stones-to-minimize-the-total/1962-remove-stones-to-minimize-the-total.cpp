class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int answer = 0;
        
        for(int i = 0; i < piles.size(); i++){
            pq.push(piles[i]);
        }
        
        while(k--){
            int top = pq.top();
            pq.pop();
            
            if(top % 2 == 1){
                top = (top / 2) + 1;
            }else{
                top = top / 2;
            }
            
            pq.push(top);
        }
        
        while(pq.empty() == false){
            answer += pq.top();
            pq.pop();
        }
        
        return answer;
    }
};