class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> answer(n, 0);
        vector<int> condition;
        
        int currentIndex = 0;
        int i = 1;
        while(true){
            if(answer[currentIndex] > 0) break;
            
            answer[currentIndex]++;
            currentIndex = (currentIndex + (k * i)) % n;
            i++;
        }
        
        for(int i = 0; i < n; i++){
            if(answer[i] == 0) condition.push_back(i + 1);
        }
        
        return condition;
    }
};