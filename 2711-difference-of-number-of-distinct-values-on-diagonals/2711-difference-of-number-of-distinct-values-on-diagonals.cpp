class Solution {
public:
    
    
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> answer(m , vector<int>(n , 0));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int topI = i - 1;
                int topJ = j - 1;
                
                int bottomI = i + 1;
                int bottomJ = j + 1;
                
                unordered_set<int> resultTop, resultBottom;
                while(topI >= 0 && topJ >= 0){
                    resultTop.insert(grid[topI][topJ]);
                    topI--;
                    topJ--;
                }
                
                while(bottomI < m && bottomJ < n){
                    resultBottom.insert(grid[bottomI][bottomJ]);
                    bottomI++;
                    bottomJ++;
                }
                
                answer[i][j] = abs((int)resultTop.size() - (int)resultBottom.size());
            }
        }
        
        return answer;
    }
};