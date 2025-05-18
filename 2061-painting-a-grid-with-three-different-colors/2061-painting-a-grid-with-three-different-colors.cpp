class Solution {
private:
    static constexpr int MOD = 1000000007;
    
    // Helper function to check if a color sequence is valid (no adjacent same colors)
    bool isValidColorSequence(const vector<int>& colors) {
        for (int i = 0; i < colors.size() - 1; ++i) {
            if (colors[i] == colors[i + 1]) {
                return false;
            }
        }
        return true;
    }
    
    // Helper function to generate all valid color masks for a row of length m
    unordered_map<int, vector<int>> generateValidMasks(int m) {
        unordered_map<int, vector<int>> valid_masks;
        int total_masks = pow(3, m);
        
        for (int mask = 0; mask < total_masks; ++mask) {
            vector<int> colors;
            int temp = mask;
            
            // Convert mask to color sequence
            for (int i = 0; i < m; ++i) {
                colors.push_back(temp % 3);
                temp /= 3;
            }
            
            if (isValidColorSequence(colors)) {
                valid_masks[mask] = move(colors);
            }
        }
        
        return valid_masks;
    }
    
    // Helper function to find all compatible adjacent masks
    unordered_map<int, vector<int>> findCompatibleMasks(const unordered_map<int, vector<int>>& valid_masks) {
        unordered_map<int, vector<int>> compatible;
        
        for (const auto& [mask1, colors1] : valid_masks) {
            for (const auto& [mask2, colors2] : valid_masks) {
                bool is_compatible = true;
                
                for (int i = 0; i < colors1.size(); ++i) {
                    if (colors1[i] == colors2[i]) {
                        is_compatible = false;
                        break;
                    }
                }
                
                if (is_compatible) {
                    compatible[mask1].push_back(mask2);
                }
            }
        }
        
        return compatible;
    }

public:
    int colorTheGrid(int m, int n) {
        // Step 1: Generate all valid color masks for a single row
        auto valid_masks = generateValidMasks(m);
        
        // Step 2: Precompute all compatible adjacent masks
        auto compatible_masks = findCompatibleMasks(valid_masks);
        
        // Step 3: Initialize DP array for the first row
        vector<int> dp(pow(3, m), 0);
        for (const auto& [mask, _] : valid_masks) {
            dp[mask] = 1;
        }
        
        // Step 4: DP for subsequent rows
        for (int row = 1; row < n; ++row) {
            vector<int> new_dp(pow(3, m), 0);
            
            for (const auto& [current_mask, _] : valid_masks) {
                for (int prev_mask : compatible_masks[current_mask]) {
                    new_dp[current_mask] = (new_dp[current_mask] + dp[prev_mask]) % MOD;
                }
            }
            
            dp = move(new_dp);
        }
        
        // Step 5: Sum all valid configurations
        int total = 0;
        for (const auto& [mask, _] : valid_masks) {
            total = (total + dp[mask]) % MOD;
        }
        
        return total;
    }
};