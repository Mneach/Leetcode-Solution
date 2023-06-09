class SubrectangleQueries {
public:
    
    
    vector<vector<int>> rectangleTemp;
    
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rectangleTemp = rectangle;
        // for(int i = 0; i < rectangle.size(); i++){
        //     for(int j = 0; j < rectangle[i].size(); j++){
        //         rectangleTemp[i][j] = rectangle[i][j];
        //     }
        // }    
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for(int i = row1; i <= row2; i++){
            for(int j = col1; j <= col2; j++){
                rectangleTemp[i][j] = newValue;
            }
        }
        
    }
    
    int getValue(int row, int col) {
        
        return rectangleTemp[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */