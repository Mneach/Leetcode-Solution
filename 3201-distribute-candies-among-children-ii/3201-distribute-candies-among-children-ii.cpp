class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ways = 0;
        
        // Iterate through all possible values for the first child
        for (int first = 0; first <= min(limit, n); first++) {
            int remaining = n - first;
            
            // Skip if remaining candies can't be distributed within limits
            if (remaining < 0 || remaining > 2 * limit) {
                continue;
            }
            
            // Calculate valid range for the second child
            int min_second = max(0, remaining - limit);
            int max_second = min(limit, remaining);
            
            // Add the number of valid combinations for this first value
            if (max_second >= min_second) {
                ways += max_second - min_second + 1;
            }
        }
        
        return ways;
    }
};