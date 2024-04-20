class Solution {
public:
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        vector<vector<int>> answer;
        
        for(int i =0 ; i < land.size(); i++){
            for(int j = 0; j < land[i].size(); j++){
                
                if(land[i][j] == 1){
                    
                    int currentRow = i;
                    int currentColumn = j;
                    
                    // cout << i << " " << currentRow << endl;
                    // cout << j << " " << currentColumn << endl;
                    // cout << endl;
                    
                    while(currentRow + 1 < land.size() && land[currentRow + 1][currentColumn] == 1){
                        currentRow++;
                    }
                    
                    while(currentColumn + 1 < land[i].size() && land[currentRow][currentColumn + 1] == 1){
                        currentColumn++;
                    }
                    
                   
                    
                    if(land[currentRow][currentColumn] == 1){
                        for(int k = i; k <= currentRow; k++){
                            for(int l = j; l <= currentColumn; l++){
                                land[k][l] = 0;
                            }
                        }
                    }else{
                        for(int k = i; k <= currentRow; k++){
                            land[k][currentColumn] = 0;
                        }
                        
                        for(int k = j; k <= currentColumn; k++){
                            land[currentRow][k] = 0;
                        }
                    }
                    
                    answer.push_back({i, j, currentRow, currentColumn});
                }
            }
        }
        
        return answer;
    }
};