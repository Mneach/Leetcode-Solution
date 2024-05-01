class Solution {
public:
    
    int answer = 1;
    void dfs(int number, int maxNumber, int minNumber, vector<bool> &dp){
        
        if(dp[number]) return;
        
        if(number % maxNumber == 0 || number % minNumber == 0) return;
        
        if(number % maxNumber != 0 && number % minNumber != 0){
            dp[number] = true;
            answer = max(answer, number);
        }
        
        if(number + maxNumber % maxNumber != 0){
            dfs(number + maxNumber, maxNumber, minNumber, dp);
        }
        
        if(number + minNumber % minNumber != 0){
            dfs(number + minNumber, maxNumber, minNumber, dp);
        }
        
        return;
    }
    
    int mostExpensiveItem(int primeOne, int primeTwo) {

        int maxNumber = max(primeOne, primeTwo);
        int minNumber = min(primeOne, primeTwo);
        vector<bool> dp((primeOne * primeTwo) + 1, false);
        
        int number = 0;
        for(int i = maxNumber; i >= 1; i--){
            if(i > minNumber && i < maxNumber && i % minNumber != 0){
                number = i;
                break;
            }
        }
        
        dfs(number, maxNumber, minNumber, dp);
        return answer;
    }
};