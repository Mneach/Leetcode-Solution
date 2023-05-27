class Solution {
public:
    
    int climb(int currentPosition, vector<int>&cost, vector<int>& dp){
        if(currentPosition == cost.size()) return 0;
        else if (currentPosition == cost.size() - 1) return cost[currentPosition];
        else if (dp[currentPosition] != -1){
            if(dp[currentPosition] < cost[currentPosition]) dp[currentPosition] = cost[currentPosition];
            
            return dp[currentPosition];
        }
        
        dp[currentPosition] = cost[currentPosition] + min(climb(currentPosition + 1, cost, dp), climb(currentPosition + 2 , cost, dp));
        return dp[currentPosition];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        vector<int> dp(cost.size() , -1);
            
        int answer = min(climb(0, cost, dp), climb(1, cost, dp));
        
        return answer;
    }
};