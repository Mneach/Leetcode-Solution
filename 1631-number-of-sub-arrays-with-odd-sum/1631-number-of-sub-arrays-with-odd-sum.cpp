class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        constexpr int MOD = 1e9 + 7;
        int count = 0, prefixSum = 0;
        int oddCount = 0, evenCount = 1;  // evenCount starts as 1 since initial sum (0) is even

        for (int num : arr) {
            prefixSum = (prefixSum + num) % 2;
            
            if (prefixSum == 0) {
                count = (count + oddCount) % MOD;
                ++evenCount;
            } else {
                count = (count + evenCount) % MOD;
                ++oddCount;
            }
        }
        
        return count;
    }
};