class Solution {
public:
    vector<int> calculateLISLengths(vector<int>& nums) {
        vector<int> lisLengths(nums.size(), 1);
        vector<int> lisSequence = {nums[0]};

        for (int i = 1; i < nums.size(); i++) {
            int pos = lower_bound(lisSequence.begin(), lisSequence.end(), nums[i]) - lisSequence.begin();

            if (pos == lisSequence.size()) {
                lisSequence.push_back(nums[i]);
            } else {
                lisSequence[pos] = nums[i];
            }

            lisLengths[i] = lisSequence.size();
        }

        return lisLengths;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> increasingSeqLength = calculateLISLengths(nums);

        reverse(nums.begin(), nums.end());
        vector<int> decreasingSeqLength = calculateLISLengths(nums);
        reverse(decreasingSeqLength.begin(), decreasingSeqLength.end());

        int minRemovals = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (increasingSeqLength[i] > 1 && decreasingSeqLength[i] > 1) {
                minRemovals = min(minRemovals, n - increasingSeqLength[i] - decreasingSeqLength[i] + 1);
            }
        }

        return minRemovals;
    }
};
