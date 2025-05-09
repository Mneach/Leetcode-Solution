class Solution {
public:
    constexpr static long long MOD = 1e9 + 7;

    int countBalancedPermutations(string num) {
        int total_sum = calculateTotalSum(num);
        if (total_sum % 2 != 0) {
            return 0;
        }

        int target = total_sum / 2;
        int n = num.size();
        int max_odd_positions = (n + 1) / 2;
        
        auto combination = precomputeCombinations(max_odd_positions);
        auto dp = initializeDP(target, max_odd_positions);
        
        processDigits(num, target, max_odd_positions, combination, dp);
        
        return dp[target][max_odd_positions];
    }

private:

    long long int max (long long a , long long b) {
        if (a > b) return a;
        else return b;
    }

    int calculateTotalSum(const string& num) {
        int sum = 0;
        for (char ch : num) {
            sum += ch - '0';
        }
        return sum;
    }

    vector<vector<long long>> precomputeCombinations(int max_odd) {
        vector<vector<long long>> comb(max_odd + 1, vector<long long>(max_odd + 1));
        for (int i = 0; i <= max_odd; i++) {
            comb[i][0] = comb[i][i] = 1;
            for (int j = 1; j < i; j++) {
                comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
            }
        }
        return comb;
    }

    vector<vector<long long>> initializeDP(int target, int max_odd) {
        vector<vector<long long>> dp(target + 1, vector<long long>(max_odd + 1));
        dp[0][0] = 1;
        return dp;
    }

    void processDigits(const string& num, int target, int max_odd, 
                      const vector<vector<long long>>& comb, 
                      vector<vector<long long>>& dp) {
        vector<int> digit_counts(10, 0);
        for (char ch : num) {
            digit_counts[ch - '0']++;
        }

        int processed_digits = 0;
        int processed_sum = 0;
        
        for (int digit = 0; digit <= 9; digit++) {
            if (digit_counts[digit] == 0) continue;
            
            processed_digits += digit_counts[digit];
            processed_sum += digit * digit_counts[digit];
            
            for (int odd_count = min(processed_digits, max_odd); 
                 odd_count >= max(0, processed_digits - (num.size() - max_odd)); 
                 odd_count--) {
                
                int even_count = processed_digits - odd_count;
                
                for (int current_sum = min(processed_sum, target);
                     current_sum >= max(0, processed_sum - target); 
                     current_sum--) {
                    
                    long long result = 0;
                    int min_j = max(0, digit_counts[digit] - even_count);
                    int max_j = min(digit_counts[digit], odd_count);
                    
                    for (int j = min_j; j <= max_j && digit * j <= current_sum; j++) {
                        long long ways = comb[odd_count][j] * 
                                        comb[even_count][digit_counts[digit] - j] % MOD;
                        result = (result + ways * dp[current_sum - digit * j][odd_count - j]) % MOD;
                    }
                    
                    dp[current_sum][odd_count] = result;
                }
            }
        }
    }
};