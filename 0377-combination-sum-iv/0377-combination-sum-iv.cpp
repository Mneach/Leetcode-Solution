#include <vector>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // Use unsigned int to prevent integer overflow (though problem constraints may prevent this)
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;  // Base case: one way to make sum 0 (use no numbers)
        
        for (int current_sum = 1; current_sum <= target; ++current_sum) {
            for (int num : nums) {
                if (num <= current_sum) {
                    dp[current_sum] += dp[current_sum - num];
                }
            }
        }
        
        return static_cast<int>(dp[target]);
    }
};