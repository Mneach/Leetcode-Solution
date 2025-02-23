class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<pair<long long, int>> pq;
        long long answer = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                pq.push({grid[i][j], i});
            }
        }

        while(k > 0) {
            auto [cell, row] = pq.top();
            pq.pop();

            if (limits[row] == 0) continue;
            limits[row]--;
            
            answer += cell;

            k--;
        }

        return answer;
    }
};