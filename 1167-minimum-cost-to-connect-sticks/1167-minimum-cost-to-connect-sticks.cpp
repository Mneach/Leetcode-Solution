class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        
        if(sticks.size() == 1){
            return 0;
        }
        
        priority_queue<int, vector<int>, greater<int> > pq;
        
        for(int i = 0; i < sticks.size(); i++){
            pq.push(sticks[i]);
        }
        
        int answer = 0;
        
        while(pq.size() > 1){
            // combine the first and second stick 
            
            int firstStick = pq.top();
            pq.pop();
            int secondStick = pq.top();
            pq.pop();
            
            int cost = firstStick + secondStick;
            pq.push(cost);
            answer += cost;
        }
        
        return answer;
    }
};