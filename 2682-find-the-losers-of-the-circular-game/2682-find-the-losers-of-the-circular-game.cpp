class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> answer(n, 0);
        vector<int> losers;
        
        int currentIndex = 0;
        int i = 1;
        while(true){
            if(answer[currentIndex] > 0) break;
            
            answer[currentIndex]++;
            currentIndex = (currentIndex + (k * i)) % n;
            i++;
        }
        
        for(int i = 0; i < n; i++){
            if(answer[i] == 0) losers.push_back(i + 1);
        }
        
        return losers;
    }
};