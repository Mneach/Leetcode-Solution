class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        if (n <= k && m <= k) {
            return 0;
        }
        long long cost = LLONG_MAX;
        long long calculate = 1LL * 2 * k;
        // Option 1: cut n, leave m (requires m <= k and n <= 2k)
        if (m <= k && n <= calculate) {
            cost = min(cost, 1LL * (n - k) * k);
        }
        // Option 2: cut m, leave n (requires n <= k and m <= 2k)
        if (n <= k && m <= calculate) {
            cost = min(cost, 1LL * (m - k) * k);
        }
        return cost != INT_MAX ? cost : 0;
    }
};