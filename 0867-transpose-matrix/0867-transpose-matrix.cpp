class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> answer;
        
        int totalRow = matrix.size();
        int totalColumn = matrix[0].size();
        
        for(int column = 0; column < totalColumn; column++){
            vector<int> bucket;
            for(int row = 0; row < totalRow; row++){
                bucket.push_back(matrix[row][column]);
            }
            answer.push_back(bucket);
        }
        
        return answer;
    }
};