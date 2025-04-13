class Solution {
public:

    int MOD = 1e9 + 7;

    int fastExpo(int x , long long n) {
        
        int result = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                result = (long long) result * x % MOD;
            }
            x = (long long) x * x % MOD;
            n /= 2;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        int result = fastExpo(5, (n + 1) / 2);
        result = ((long long)result % MOD * fastExpo(4, n / 2) % MOD) % MOD;
        return result;
    }
};