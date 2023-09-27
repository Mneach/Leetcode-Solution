class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        
        vector<priority_queue<int>> arr;
        
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            priority_queue<int> temp;
            
            for(int j = 0; j < n; j++){
                temp.push(grid[i][j]);
            }
            
            arr.push_back(temp);
        }
        
        int answer = 0;
        for(int i = 0; i < n; i++){
            int maximum = INT_MIN;
            
            for(int j = 0; j < m; j++){
                maximum = max(arr[j].top(), maximum);
                arr[j].pop();
            }
            answer += maximum;
        }
        
        return answer;
    }
};