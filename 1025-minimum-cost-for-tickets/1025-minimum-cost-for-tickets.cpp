class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastDay = days.back();
        vector<int> dp(lastDay + 1, 0);
        unordered_set<int> travelDays(days.begin(), days.end());

        for (int day = 1; day <= lastDay; ++day) {
            if (!travelDays.count(day)) {
                dp[day] = dp[day - 1];
            } else {
                dp[day] = min({
                    dp[day - 1] + costs[0],
                    dp[max(0, day - 7)] + costs[1],
                    dp[max(0, day - 30)] + costs[2]
                });
            }
        }

        return dp[lastDay];
    }
};
