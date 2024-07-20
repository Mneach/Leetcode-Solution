class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        
        vector<vector<int>> answer(rowSum.size(), vector<int>(colSum.size(), 0));

        int row = 0; 
        int column = 0;

        int totalRow = rowSum.size();
        int totalColumn = colSum.size();

        while(row < totalRow && column < totalColumn){
            cout << row << " " << column << endl;
            answer[row][column] = min(rowSum[row], colSum[column]);

            rowSum[row] -= answer[row][column];
            colSum[column] -= answer[row][column];

            if(rowSum[row] == 0 && colSum[column] != 0){
                // move to the bottom
                row++;
            }else if(rowSum[row] != 0 && colSum[column] == 0){
                column++;
            }else{
                row++;
                column++;
            }
        }

        return answer;

    }
};