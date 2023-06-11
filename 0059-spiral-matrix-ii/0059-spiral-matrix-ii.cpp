class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n,0));
        int flag = 1;
        
        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = n - 1;
        int currentValue = 1;

        while(left <= right && top <= bottom){

       if(flag == 1){
         for(int i = left; i <= right; i++){ 
           matrix[left][i] = currentValue;
           currentValue++;
         }
         flag = 2;
         top++;
       }else if(flag == 2){
         for(int i = top; i <= bottom; i++){
           matrix[i][right] = currentValue;
           currentValue++;
         }
         flag = 3;
         right--;
       }else if(flag == 3){
        for(int i = right; i >= left; i--){
           matrix[bottom][i] = currentValue;
           currentValue++;
          }
          flag = 4;
          bottom--;
        }else if(flag == 4){
           for(int i = bottom; i >= top; i--){
             matrix[i][left] = currentValue;
             currentValue++;
           }
           flag = 1;
           left++;
         }
       }
        return matrix;
    }
};