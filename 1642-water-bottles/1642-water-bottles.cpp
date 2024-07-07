class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int answer = 0;
        int emptyBottle = 0;
        while(numBottles > 0){
            answer += numBottles;
            emptyBottle += numBottles % numExchange;
            numBottles /= numExchange;

            int reminder = emptyBottle / numExchange;
            if(reminder >= 0){
                numBottles += reminder;
                emptyBottle -= (numExchange * reminder);
            }
            
        }

        return answer;
    }
};