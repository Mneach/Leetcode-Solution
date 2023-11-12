class Solution {
public:
    string predictPartyVictory(string input) {
        
       queue<int> direQueue;
	queue<int> radiantQueue;

	for(int i = 0; i < input.length(); i++){
		if(input[i] == 'R'){
		    radiantQueue.push(i);
        }else{
            direQueue.push(i);
        }
    }

    // ban 
    while(direQueue.empty() == false && radiantQueue.empty() == false){
            int direIndex = direQueue.front();
            int radiantIndex = radiantQueue.front();

            direQueue.pop();
            radiantQueue.pop();

            if(direIndex < radiantIndex){
            // ban radiant
            // push current direIndex ke dalam queue
            direQueue.push(direIndex + input.length());
        }else{
            // ban dire
            // push current radiantIndex ke dalam queue
            radiantQueue.push(radiantIndex + input.length());
        }
    }

    // Announce Victory
    if(radiantQueue.empty()){
        return "Dire";
    }else{
        return "Radiant";
    }

    }
};