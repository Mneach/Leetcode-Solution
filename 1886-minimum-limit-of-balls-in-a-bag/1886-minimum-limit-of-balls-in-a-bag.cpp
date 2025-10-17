class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int minPenalty = 1;
        int maxPenalty = *max_element(nums.begin(), nums.end());
        int result = maxPenalty;

        while (minPenalty <= maxPenalty) {
            int penalty = minPenalty + (maxPenalty - minPenalty) / 2;

            cout << penalty << endl;

            // check if current penalty is a valid answer
            long long totalOperations = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= penalty) {
                    continue;
                }

                if (nums[i] % penalty == 0) {
                    totalOperations += (1LL * nums[i] / penalty) - 1;
                } else {
                    totalOperations += (1LL * nums[i] / penalty);
                }
            }

            if (totalOperations <= maxOperations) {
                result = penalty;
                maxPenalty = penalty - 1;
            } else {
                minPenalty = penalty + 1;
            }
        }

        return result;
    }
};