class Solution {
public:

    void sieve(vector<bool> &isPrime) {
        isPrime[0] = false;
        isPrime[1] = false;
        
        for (int i = 2; i < 1e3 + 1; i++) {
            
            if (isPrime[i] == false) continue;
            isPrime[i] = true;
            for (int j = i * i; j < 1e6 + 1; j += i) {
                isPrime[j] = false;
            }
        }
    }

    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(1e6 + 1, true);
        vector<int> answer;
        sieve(isPrime);    
        while (left <= right) {
            if (isPrime[left] == true) {
                answer.push_back(left);
            }
            left++;
        }

        if (answer.size() <= 1) return {-1, -1};

        int current = INT_MAX;
        int first = -1;
        int second = -1;
        for (int i = 1; i < answer.size(); i++) {
            if (answer[i] - answer[i - 1] < current) {
                first = answer[i - 1];
                second = answer[i];
                current = second - first;
            }
        }
        
        return {first, second};
    }
};