class Solution {
public:
    
    int findMax(vector<int> &startTime, vector<vector<int>>& jobs){
        int size = startTime.size();
        vector<int> dp(50001, 0);
        
        
        for(int i = size - 1; i >= 0; i--){
            int currentProfit = 0;
            
            int searchNext = lower_bound(startTime.begin(), startTime.end(), jobs[i][1]) - startTime.begin();
            
            if(searchNext == size){
                currentProfit = jobs[i][2];
            }else{
                currentProfit = jobs[i][2] + dp[searchNext];
            }
            
            if(i == size - 1){
                dp[i] = currentProfit;
            }else{
                dp[i] = max(currentProfit, dp[i + 1]);
            }
            
        }
        return dp[0];
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
       
        vector<vector<int>> totalJobs;
        
        for(int i = 0; i < startTime.size(); i++){
            totalJobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        sort(totalJobs.begin(), totalJobs.end());
        
        for(int i = 0; i < startTime.size(); i++){
            startTime[i] = totalJobs[i][0];
        }
        
        int answer = findMax(startTime, totalJobs);
        
        return answer;
    }
};