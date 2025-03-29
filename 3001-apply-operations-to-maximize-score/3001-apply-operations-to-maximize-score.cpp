using namespace std;

class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> primeScores(n, 0);
        int maxElement = *max_element(nums.begin(), nums.end());
        
        vector<int> primes = getPrimes(maxElement);
        computePrimeScores(nums, primes, primeScores);
        
        vector<int> nextDominant(n, n), prevDominant(n, -1);
        computeDominantIndices(primeScores, nextDominant, prevDominant);
        
        vector<long long> numOfSubarrays(n);
        for (int i = 0; i < n; i++) {
            numOfSubarrays[i] = (long long)(nextDominant[i] - i) * (i - prevDominant[i]);
        }
        
        vector<pair<int, int>> sortedArray(n);
        for (int i = 0; i < n; i++) {
            sortedArray[i] = {nums[i], i};
        }
        sort(sortedArray.rbegin(), sortedArray.rend());
        
        long long score = 1;
        int index = 0;
        while (k > 0) {
            auto [num, i] = sortedArray[index++];
            long long operations = min((long long)k, numOfSubarrays[i]);
            score = (score * power(num, operations)) % MOD;
            k -= operations;
        }
        return score;
    }

private:
    vector<int> getPrimes(int limit) {
        vector<bool> isPrime(limit + 1, true);
        vector<int> primes;
        for (int num = 2; num <= limit; num++) {
            if (!isPrime[num]) continue;
            primes.push_back(num);
            for (long long multiple = (long long)num * num; multiple <= limit; multiple += num) {
                isPrime[multiple] = false;
            }
        }
        return primes;
    }

    void computePrimeScores(const vector<int>& nums, const vector<int>& primes, vector<int>& primeScores) {
        for (size_t i = 0; i < nums.size(); i++) {
            int num = nums[i];
            for (int prime : primes) {
                if (prime * prime > num) break;
                if (num % prime == 0) {
                    primeScores[i]++;
                    while (num % prime == 0) num /= prime;
                }
            }
            if (num > 1) primeScores[i]++;
        }
    }

    void computeDominantIndices(const vector<int>& primeScores, vector<int>& nextDominant, vector<int>& prevDominant) {
        stack<int> decreasingStack;
        for (size_t i = 0; i < primeScores.size(); i++) {
            while (!decreasingStack.empty() && primeScores[decreasingStack.top()] < primeScores[i]) {
                nextDominant[decreasingStack.top()] = i;
                decreasingStack.pop();
            }
            if (!decreasingStack.empty()) prevDominant[i] = decreasingStack.top();
            decreasingStack.push(i);
        }
    }

    long long power(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }
};
