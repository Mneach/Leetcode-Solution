class Solution {
private:
    static constexpr int NUM_CHARS = 5; // '0' to '4'
    static constexpr int NUM_STATES = 4; // 2^2 possible parity combinations
    
    // Calculate parity state based on character counts
    // Returns: (count_a % 2) * 2 + (count_b % 2)
    int getParityState(int countA, int countB) const {
        return ((countA & 1) << 1) | (countB & 1);
    }
    
    // Find maximum difference for a specific character pair
    int findMaxDifferenceForPair(const string& s, char charA, char charB, int k) const {
        const int n = s.size();
        
        // Track minimum difference for each parity state
        vector<int> minDifference(NUM_STATES, INT_MAX);
        
        int countA = 0, countB = 0;
        int prefixA = 0, prefixB = 0;
        int left = -1;
        int maxDiff = INT_MIN;
        
        for (int right = 0; right < n; ++right) {
            // Update counts for current window
            if (s[right] == charA) countA++;
            if (s[right] == charB) countB++;
            
            // Shrink window if conditions are met
            while (right - left >= k && (countB - prefixB) >= 2) {
                int leftState = getParityState(prefixA, prefixB);
                minDifference[leftState] = min(minDifference[leftState], 
                                             prefixA - prefixB);
                
                left++;
                if (s[left] == charA) prefixA++;
                if (s[left] == charB) prefixB++;
            }
            
            // Check for valid combination with complementary parity
            int rightState = getParityState(countA, countB);
            int targetState = rightState ^ 0b10; // Flip the 'A' parity bit
            
            if (minDifference[targetState] != INT_MAX) {
                int currentDiff = (countA - countB) - minDifference[targetState];
                maxDiff = max(maxDiff, currentDiff);
            }
        }
        
        return maxDiff;
    }
    
public:
    int maxDifference(string s, int k) {
        int globalMaxDiff = INT_MIN;
        
        // Try all pairs of distinct characters from '0' to '4'
        for (char charA = '0'; charA < '0' + NUM_CHARS; ++charA) {
            for (char charB = '0'; charB < '0' + NUM_CHARS; ++charB) {
                if (charA != charB) {
                    int pairMaxDiff = findMaxDifferenceForPair(s, charA, charB, k);
                    globalMaxDiff = max(globalMaxDiff, pairMaxDiff);
                }
            }
        }
        
        return globalMaxDiff;
    }
};