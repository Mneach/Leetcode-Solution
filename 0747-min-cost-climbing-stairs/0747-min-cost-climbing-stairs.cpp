class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int x = cost[0];
        int y = cost[1];

        for (int i = 2; i < cost.size(); i++) {
            int result = cost[i] + min(x , y);
            x = y;
            y = result;
        }

        return min(x , y);
    }
};