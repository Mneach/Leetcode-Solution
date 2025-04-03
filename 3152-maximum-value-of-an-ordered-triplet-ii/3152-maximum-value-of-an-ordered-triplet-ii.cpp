class Solution {
public:

    long long max(long long a, long long b) {
        if (a > b) return a;
        else return b;
    }

    long long maximumTripletValue(vector<int>& nums) {
        vector<long long> prefixMax(nums.size(), 0);
        vector<long long> suffixMax(nums.size(), 0);
        long long answer = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                prefixMax[i] = nums[i];
            } else {
                prefixMax[i] = max(prefixMax[i - 1], nums[i]);
            }
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i == nums.size() - 1) {
                suffixMax[i] = nums[i];
            } else {
                suffixMax[i] = max(nums[i], suffixMax[i + 1]);
            }
        }

        // formula
        // (prefixMax[left] - nums[current]) * suffixMax[current + 1]
        int left = 0;
        int current = 1;

        while (left < nums.size() - 1 && current < nums.size() - 1) {
            if (prefixMax[left] != prefixMax[current]) {
                left = current;
            } else {
                long long result = (prefixMax[left] - nums[current]) * suffixMax[current + 1];
                answer = max(answer, result);
            }
            current++;
        }

        return answer;
    }
};