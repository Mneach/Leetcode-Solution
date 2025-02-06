class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int answer = 0;
        vector<long long> prefixSum(1001, 0);
        unordered_map<long long,int> ump;

        // precompute
        for (int i = 1; i < prefixSum.size(); i++) {
            prefixSum[i] = ((i - 1) * 4) * i;
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                long long result = 1LL * nums[i] * nums[j];
                ump[result]++;
            }
        }

        for (auto data : ump) {
            answer += prefixSum[data.second];
        }

        return answer;
    }
};