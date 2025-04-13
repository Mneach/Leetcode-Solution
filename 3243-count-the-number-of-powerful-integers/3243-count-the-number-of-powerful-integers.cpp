class Solution {
public:

    long long max(long long a, long long b) {
        if (a > b) return a;
        else return b;
    }

    long long cache[20][2];

    long long dfs(string num, string s, int tight, int n, int limit) {
        if (num.length() < s.length()) return 0;
        else if (cache[n][tight] != -1) return cache[n][tight];

        int upperBound = tight ? num[num.length() - n] - '0' : limit;
        long long result = 0;

        if (n == 1) {
            int currentS = s[s.length() - n] - '0';
            if (currentS > upperBound) {
                return 0;
            } else {
                return 1;
            }
        } 
        
        if (n <= s.length()) {
            if (tight) {
                int currentS = s[s.length() - n] - '0';

                if (currentS > upperBound) {
                    return 0;
                } else if (currentS == upperBound) {
                    result = result + dfs(num , s , 1, n - 1, limit);
                    return result;
                } else {
                    return 1;
                }
            } else {
                return 1;
            }
        } else {
            for (int i = 0; i <= upperBound && i <= limit; i++) {
                result = (result + dfs(num, s , tight & (upperBound == i), n - 1, limit));
            }
        }
        return cache[n][tight] = result;
    }

    void resetCache() {
        memset(cache, -1, sizeof(cache));
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string left = to_string(start - 1);
        string right = to_string(finish);
        resetCache();
        long long resultRight = dfs(right, s, 1, right.length(), limit);
        resetCache();
        long long resultLeft = dfs(left, s, 1, left.length(), limit);

        return max(0, resultRight - resultLeft);
    }
};