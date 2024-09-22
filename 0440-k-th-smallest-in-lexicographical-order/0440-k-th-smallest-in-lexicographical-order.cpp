class Solution {
private:

    int min(long long a, long long b){
        if(a > b) return b;
        else return a;
    }

    int helper(long long currentNumber, long long n){
        int result = 0;
        long long neighbor = currentNumber + 1;

        while(currentNumber <= n){
            result += min((n + 1), neighbor) - currentNumber;
            currentNumber *= 10;
            neighbor *= 10;
        }

        return result;
    }

public:
    int findKthNumber(int n, int k) {
        
        int currentNumber = 1;
        int index = 1;

        while(index < k){
            int steps = helper(currentNumber, n);
            cout << steps << endl;
            if(index + steps <= k){
                // move current to the neightboar
                currentNumber += 1;
                
                // increment the index by steps
                index += steps;
            }else{
                // move to the left
                currentNumber *= 10;
                index += 1;
            }
        }

        return currentNumber;
    }
};