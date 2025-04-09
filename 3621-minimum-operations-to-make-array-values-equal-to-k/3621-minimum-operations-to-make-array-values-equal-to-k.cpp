class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> bucket;

        for (auto num : nums) {
            if (num < k) {
                return -1;
            } else if (num > k) {
                bucket.insert(num);
            }
        }

        return bucket.size();
    }
};