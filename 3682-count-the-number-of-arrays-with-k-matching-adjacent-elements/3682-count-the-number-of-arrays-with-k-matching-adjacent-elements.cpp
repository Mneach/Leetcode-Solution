#include <vector>

class GoodArrayCounter {
private:
    static constexpr int MOD = 1'000'000'007;
    static constexpr int MAX_N = 100'000;
    
    // Precomputed factorial and inverse factorial tables
    static std::vector<long long> factorial;
    static std::vector<long long> inv_factorial;
    
    // Flag to track initialization
    static bool initialized;
    
    // Initialize factorial and inverse factorial tables
    static void initialize() {
        if (initialized) return;
        
        factorial.resize(MAX_N + 1);
        inv_factorial.resize(MAX_N + 1);
        
        // Compute factorials
        factorial[0] = 1;
        for (int i = 1; i <= MAX_N; ++i) {
            factorial[i] = (factorial[i - 1] * i) % MOD;
        }
        
        // Compute inverse factorials using Fermat's Little Theorem
        inv_factorial[MAX_N] = modExp(factorial[MAX_N], MOD - 2);
        for (int i = MAX_N - 1; i >= 0; --i) {
            inv_factorial[i] = (inv_factorial[i + 1] * (i + 1)) % MOD;
        }
        
        initialized = true;
    }
    
    // Modular exponentiation (binary exponentiation)
    static long long modExp(long long base, int exponent) {
        long long result = 1;
        while (exponent > 0) {
            if (exponent & 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exponent >>= 1;
        }
        return result;
    }

public:
    // Compute combinations (n choose k) modulo MOD
    static long long combinations(int n, int k) {
        if (!initialized) initialize();
        if (k < 0 || k > n) return 0;
        return factorial[n] * inv_factorial[k] % MOD * inv_factorial[n - k] % MOD;
    }
    
    // Count the number of good arrays
    static int count(int n, int m, int k) {
        if (!initialized) initialize();
        
        // Edge case: arrays of length 1
        if (n == 1) {
            return k == 0 ? m : 0;
        }
        
        // Validate input constraints
        if (k < 0 || k >= n) {
            return 0;
        }
        
        long long count = combinations(n - 1, k);
        count = (count * m) % MOD;
        count = (count * modExp(m - 1, n - k - 1)) % MOD;
        
        return static_cast<int>(count);
    }
};

// Initialize static members
std::vector<long long> GoodArrayCounter::factorial;
std::vector<long long> GoodArrayCounter::inv_factorial;
bool GoodArrayCounter::initialized = false;

class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        return GoodArrayCounter::count(n, m, k);
    }
};