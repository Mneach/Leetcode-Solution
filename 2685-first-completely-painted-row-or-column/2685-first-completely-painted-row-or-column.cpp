class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int totalRow = mat.size();
        int totalCol = mat[0].size();

        vector<int> row(totalRow, 0);
        vector<int> col(totalCol, 0);
        unordered_map<int,pair<int,int>> ump;

        for (int i = 0; i < totalRow; i++) {
            for (int j = 0; j < totalCol; j++) {
                ump[mat[i][j]] = make_pair(i, j);
            }
        }

        for (int index = 0; index < arr.size(); index++) {
            int num = arr[index];
            pair<int,int> position = ump[num];

            int currentRow = position.first;
            int currentCol = position.second;

            row[currentRow]++;
            col[currentCol]++;

            if (row[currentRow] == totalCol) {
                return index;
            } 
            
            if (col[currentCol] == totalRow) {
                return index;
            }
        }
        return -1;
    }
};