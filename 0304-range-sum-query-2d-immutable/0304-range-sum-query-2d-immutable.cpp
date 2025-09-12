/*

How to solve the problem : 

# Prefix Sum 2D Approach
1. Create the prefix sum 2D using this formula
   - prefixSumRow = prefixSumRow += previous number
   - prefixSumMat = sumMat[row][col + 1]
   - currentSum = prefixSumRow + prefixSumMat
2. to compute the answer we can use this formula
   - sumRegion = sumMatrix - bottom left sum matrix - top sum matrix + top left sum matrix (because of there is an intersaction between bottom left sum matrix and top sum matrix)
   - sumRegion = sumMat[row2][col2] - sumMat[row2][col1 - 1] - sumMat[row1 - 1] [col2] + sumMat[row - 1][col -1]

Notes : 
1. we will fill index row 0 and col 0 with value 0, so we will start at index 1 for row and col. so it will be easier for us to computer the answer

*/

class NumMatrix {
public:

    vector<vector<int>> sumMat;

    NumMatrix(vector<vector<int>>& matrix) {
        int totalRow = matrix.size();
        int totalCol = matrix[0].size();

        sumMat = vector<vector<int>>(totalRow + 1, vector<int>(totalCol + 1, 0));

        for (int row = 0; row < totalRow; row++) {
            int prefix = 0;

            for (int col = 0; col < totalCol; col++) {
                prefix += matrix[row][col];
                sumMat[row + 1][col + 1] = prefix + sumMat[row][col + 1];
            }
        }

        // for (int i = 0; i < sumMat.size(); i++) {
        //     for (int j = 0; j < sumMat[i].size(); j++) {
        //         cout << sumMat[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;
        row2++;
        col1++;
        col2++;

        int sumMatrix = sumMat[row2][col2];
        int bottomLeft = sumMat[row2][col1 - 1];
        int top = sumMat[row1 - 1][col2];
        int topLeft = sumMat[row1 - 1][col1 - 1];

        return sumMatrix - bottomLeft - top + topLeft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */