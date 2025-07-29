class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> left, right, count;
        for (int i = 0; i < nums.size(); ++i) {
            int x = nums[i];
            if (left.find(x) == left.end()) {
                left[x] = i;
            }
            right[x] = i;
            count[x]++;
        }

        int degree = 0;
        for (const auto& p : count) {
            degree = max(degree, p.second);
        }

        int ans = nums.size();
        for (const auto& p : count) {
            if (p.second == degree) {
                ans = min(ans, right[p.first] - left[p.first] + 1);
            }
        }

        return ans;
    }
};
