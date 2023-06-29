class Solution {
public:
    string predictPartyVictory(string senate) {
        
        queue<int> radiantQueue;
        queue<int> direQueue;
        
        for(int i = 0; i < senate.length(); i++){
            if(senate[i] == 'R') radiantQueue.push(i);
            else direQueue.push(i);
        }
        
        while(radiantQueue.empty() == false && direQueue.empty() == false){
            
            int direIndex = direQueue.front();
            int radiantIndex = radiantQueue.front();
            
            direQueue.pop();
            radiantQueue.pop();
            
            if(direIndex < radiantIndex){
                direQueue.push(direIndex + senate.size());
            }else{
                radiantQueue.push(radiantIndex + senate.size());
            }
        }
        
        if(radiantQueue.empty()) return "Dire";
        else return "Radiant";
    }
};