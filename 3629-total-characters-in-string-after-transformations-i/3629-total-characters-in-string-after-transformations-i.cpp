class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> charCounts(26, 0);
        countInitialCharacters(s, charCounts);
        
        for (int round = 0; round < t; ++round) {
            charCounts = computeNextCounts(charCounts);
        }
        
        return calculateTotalLength(charCounts);
    }

private:
    static constexpr int MOD = 1000000007;
    
    void countInitialCharacters(const string& s, vector<int>& counts) {
        for (char ch : s) {
            ++counts[ch - 'a'];
        }
    }
    
    vector<int> computeNextCounts(const vector<int>& currentCounts) {
        vector<int> nextCounts(26);
        
        // 'z' transforms to 'a' and 'b'
        nextCounts[0] = currentCounts[25];  // New 'a's from 'z's
        nextCounts[1] = (currentCounts[25] + currentCounts[0]) % MOD;  // New 'b's from 'a's and 'z's
        
        // Other letters simply shift forward
        for (int i = 2; i < 26; ++i) {
            nextCounts[i] = currentCounts[i - 1];
        }
        
        return nextCounts;
    }
    
    int calculateTotalLength(const vector<int>& counts) {
        int total = 0;
        for (int count : counts) {
            total = (total + count) % MOD;
        }
        return total;
    }
};