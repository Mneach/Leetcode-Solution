class Solution {
public:

    long long min (long long a, long long b) {
        if (a > b) return b;
        else return a;
    }

    long long max (long long a, long long b) {
        if (a > b) return a;
        else return b;
    }

    long long gridGame(vector<vector<int>>& grid) {
        vector<vector<long long>> prefixSum(2, vector<long long>(grid[0].size(), 0));

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (j == 0) {
                    prefixSum[i][j] = grid[i][j];
                } else {
                    prefixSum[i][j] += grid[i][j] + prefixSum[i][j - 1];
                }
            }
        }

        long long answer = LLONG_MAX;

        for (int i = 0; i < grid[0].size(); i++) {
            long long topResult = 0;
            long long bottomResult = 0;

            if (i == 0) {
                topResult = prefixSum[0][grid[0].size() - 1] - prefixSum[0][0];
                bottomResult = 0;
            } else {
                topResult = prefixSum[0][grid[0].size() - 1] - prefixSum[0][i];
                bottomResult = prefixSum[1][i - 1];
            }

            answer = min(answer, max(topResult, bottomResult));
        }

        return answer;
    }
};