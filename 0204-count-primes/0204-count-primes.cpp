class Solution {
public:
    int countPrimes(int n) {
        int maxConstraints = 5000000;
        
        vector<bool> primes(maxConstraints + 1, true);
        
        int answer = 0;
        for(long long i = 2; i < n; i++){
            if(primes[i] == true){
                for(long long j = i * i; j <= n; j += i) primes[j] = false;
                answer++;
            }
        }
        
        return answer;
    }
};