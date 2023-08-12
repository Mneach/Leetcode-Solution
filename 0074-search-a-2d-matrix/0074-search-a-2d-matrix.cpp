class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        for(int i = 0; i < matrix.size(); i++){
            
            if(target >= matrix[i][0] && target <= matrix[i][matrix[i].size() - 1]){
                int left = 0;
                int right = matrix[i].size() - 1;
                while(left <= right){
                    
                    int mid = (left + right) / 2;
                    cout << mid << endl;
                    
                    if(matrix[i][mid] == target) return true;
                    else if(matrix[i][mid] < target) left = mid + 1;
                    else if(matrix[i][mid] > target) right = mid - 1;
                }
            }
        }
        
        return false;
    }
};