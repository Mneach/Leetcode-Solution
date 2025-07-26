class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> positiveNumsSet;
        for (int num : nums) {
            if (num > 0) {
                positiveNumsSet.emplace(num);
            }
        }

        if (positiveNumsSet.empty()) {
            int result = INT_MIN;
            for (auto data : nums) {
                if (result == INT_MIN) result = data;
                else result = max(result, data);
            }

            return result;
        }
        return accumulate(positiveNumsSet.begin(), positiveNumsSet.end(), 0);
    }
};