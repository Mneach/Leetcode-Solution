const int MOD = 1e9 + 7;
const int MAX_N = 1e4 + 10;
const int MAX_P = 15; // Maximum number of prime factors

int binomialCoeff[MAX_N + MAX_P][MAX_P + 1];
std::vector<int> primeFactorCounts[MAX_N];
int smallestPrime[MAX_N];

class Solution {
public:
    Solution() {
        static bool initialized = initialize(); // Ensure one-time setup
    }

    int idealArrays(int n, int maxValue) {
        long long totalWays = 0;

        for (int val = 1; val <= maxValue; ++val) {
            long long ways = 1;
            for (int count : primeFactorCounts[val]) {
                ways = ways * binomialCoeff[n + count - 1][count] % MOD;
            }
            totalWays = (totalWays + ways) % MOD;
        }

        return static_cast<int>(totalWays);
    }

private:
    static bool initialize() {
        buildSieve();
        buildPrimeFactorCounts();
        computeBinomialCoefficients();
        return true;
    }

    static void buildSieve() {
        for (int i = 2; i < MAX_N; ++i) {
            if (smallestPrime[i] == 0) {
                for (int j = i; j < MAX_N; j += i) {
                    if (smallestPrime[j] == 0) {
                        smallestPrime[j] = i;
                    }
                }
            }
        }
    }

    static void buildPrimeFactorCounts() {
        for (int i = 2; i < MAX_N; ++i) {
            int x = i;
            while (x > 1) {
                int prime = smallestPrime[x];
                int count = 0;
                while (x % prime == 0) {
                    x /= prime;
                    ++count;
                }
                primeFactorCounts[i].push_back(count);
            }
        }
    }

    static void computeBinomialCoefficients() {
        binomialCoeff[0][0] = 1;
        for (int i = 1; i < MAX_N + MAX_P; ++i) {
            binomialCoeff[i][0] = 1;
            for (int j = 1; j <= std::min(i, MAX_P); ++j) {
                binomialCoeff[i][j] = (binomialCoeff[i - 1][j] + binomialCoeff[i - 1][j - 1]) % MOD;
            }
        }
    }
};
