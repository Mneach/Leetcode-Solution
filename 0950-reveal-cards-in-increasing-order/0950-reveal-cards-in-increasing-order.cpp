class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        sort(deck.begin(), deck.end());
        int deckSize = deck.size();
        
        vector<int> answer(deckSize);
       
        queue<int> q;
        for(int i = 0; i < deckSize; i++) q.push(i);
        
        int currentDeckIndex = 0;
        bool flipDeck = true;
        
        while(q.size() > 0){
           
            if(flipDeck){
                answer[q.front()] = deck[currentDeckIndex];
                currentDeckIndex++;
                q.pop();
            }else{
                q.push(q.front());
                q.pop();
            }
            
            if(flipDeck) flipDeck = false;
            else flipDeck = true;
        }
        
        return answer;
    }
};