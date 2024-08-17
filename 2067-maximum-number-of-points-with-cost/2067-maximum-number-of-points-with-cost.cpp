class Solution {
public:

    long long max(long long a, long long b){
        if(a > b) return a;
        else return b;
    }

    long long maxPoints(vector<vector<int>>& points) {
        long long answer = 0;
        int totalRow = points.size();
        int totalColumn = points[0].size();

        vector<long long int> dp(totalColumn);

        for(int i = 0; i < totalColumn; i++){
            dp[i] = points[totalRow - 1][i];  
        }

        for(int row = totalRow - 2; row >= 0; row--){
            vector<long long int> left(totalColumn);
            vector<long long int> right(totalColumn);
            vector<long long int> current(totalColumn);

            left[0] = dp[0];
            for(int column = 1; column < totalColumn; column++){
                left[column] = max(left[column - 1] - 1, dp[column]);
            }

            right[totalColumn - 1] = dp[totalColumn - 1];
            for(int column = totalColumn - 2; column >= 0; column--){
                right[column] = max(right[column + 1] - 1, dp[column]);
            }


            for(int column = 0; column < totalColumn; column++){
                current[column] = points[row][column] + max(left[column], right[column]);
            }

            dp = current;
        
        }
        
        for(int i = 0; i < totalColumn; i++){
            answer = max(answer, dp[i]);
        }

        return answer;
    }
};