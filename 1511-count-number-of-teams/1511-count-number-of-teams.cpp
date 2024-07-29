class Solution {
public:

    int recursiveIncrease(vector<int>& rating, int currentIndex, int teamSize, vector<vector<int>> &dp){

        if(currentIndex >= rating.size()){
            return 0;
        }

        if(teamSize == 3) return 1;

        if(dp[currentIndex][teamSize] != -1){
            return dp[currentIndex][teamSize];
        }

        int answer = 0;

        for(int i = currentIndex + 1; i < rating.size(); i++){
            if(rating[currentIndex] < rating[i]){
                answer += recursiveIncrease(rating, i, teamSize + 1, dp);
            }
        }

        dp[currentIndex][teamSize] = answer;

        return dp[currentIndex][teamSize];
    }

    int recursiveDecrease(vector<int>& rating, int currentIndex, int teamSize, vector<vector<int>> &dp){

        if(currentIndex >= rating.size()){
            return 0;
        }

        if(teamSize == 3) return 1;

        if(dp[currentIndex][teamSize] != -1){
            return dp[currentIndex][teamSize];
        }

        int answer = 0;

        for(int i = currentIndex + 1; i < rating.size(); i++){
            if(rating[currentIndex] > rating[i]){
                answer += recursiveDecrease(rating, i, teamSize + 1, dp);
            }
        }

        dp[currentIndex][teamSize] = answer;

        return dp[currentIndex][teamSize];
    }    

    int numTeams(vector<int>& rating) {
        vector<vector<int>> dpDecrease(rating.size(), vector<int>(4, -1));
        vector<vector<int>> dpIncrease(rating.size(), vector<int>(4, -1));

        int answer = 0;
        for(int i = 0; i < rating.size(); i++){
            int increase = recursiveIncrease(rating, i, 1, dpIncrease);
            int decrease = recursiveDecrease(rating, i, 1, dpDecrease);

            answer += increase + decrease;
        }

        return answer;
    }
};