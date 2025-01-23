class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int totalRow = grid.size();
        int totalCol = grid[0].size();
        vector<vector<bool>> visited(totalRow, vector<bool>(totalCol, false));
        int answer = 0;
        
        for (int row = 0; row < totalRow; row++) {
            int temp = 0;
            int firstCol = -1;
            for (int col = 0; col < totalCol; col++) {
                if (grid[row][col] == 1) {
                    visited[row][col] = true;
                    firstCol = col;
                    temp++;
                }
            }

            if (temp == 1) {
                visited[row][firstCol] = false;
            } else {
                answer += temp;
            }
        }

        for (int col = 0; col < totalCol; col++) {
            int temp = 0;
            int totalVisited = 0;
            for (int row = 0; row < totalRow; row++) {
                if (grid[row][col] == 1) {
                    if (visited[row][col] == true) {
                        totalVisited++;
                    } else {
                        temp++;
                    }
                }
            }

            if (totalVisited + temp > 1) {
                answer += temp;
            }
        }

        return answer;
    }
};