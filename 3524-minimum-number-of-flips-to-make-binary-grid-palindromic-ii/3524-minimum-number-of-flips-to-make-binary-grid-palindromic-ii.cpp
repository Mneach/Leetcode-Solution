class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        
        int answer = 0;
        int totalRow = grid.size();
        int totalColumn = grid[0].size();

        for(int top = 0; top < totalRow / 2; top++){
            int bottom = totalRow - top - 1;
            for(int left = 0; left < totalColumn / 2; left++){
                int right = totalColumn - left - 1;

                int current = grid[top][left];
                
                // plus bottom
                current += grid[bottom][left];
                // plus right
                current += grid[top][right];
                // plus diagonal
                current += grid[bottom][right];

                answer += min(current, 4 - current);
            }
        }

        int countPair = 0;
        int totalFlip = 0;
        
        if(totalRow % 2 == 1){
            int row = totalRow / 2;
            int column = totalColumn / 2;
            for(int left = 0; left < column; left++){
                int right = totalColumn - left - 1;

                if(grid[row][left] != grid[row][right]){
                    answer++;
                    totalFlip++;
                }

                if(grid[row][left] == grid[row][right] && grid[row][left] == 1){
                    countPair++;
                }
            }
        }

        if(totalColumn % 2 == 1){
            int row = totalRow / 2;
            int column = totalColumn / 2;

            for(int top = 0; top < row; top++){
                int bottom = totalRow - top - 1;

                cout << top << " " << bottom << endl;

                if(grid[top][column] != grid[bottom][column]){
                    answer++;
                    totalFlip++;
                }

                if(grid[top][column] == grid[bottom][column] && grid[top][column] == 1){
                    countPair++;
                }                
            }
        }

        cout << answer << " " << totalFlip << " " << countPair << endl;

        if(countPair % 2 == 1 && totalFlip == 0) {
            answer += 2;
        }

        if(grid[totalRow / 2][totalColumn / 2] == 1 && totalRow % 2 == 1 && totalColumn % 2 == 1){
            answer += 1;
        }

        return answer;
    }
};