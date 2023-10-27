class Solution {
public:
    
    void floodFill(int column, int row, vector<vector<int>>& image, int color, int searchColor){
        
        if(row < 0 || column < 0) return;
        else if(row == image.size() || column == image[0].size()) return;
        else if(image[row][column] != searchColor) return;
        else if(image[row][column] == color) return;
        
        image[row][column] = color;
        
        floodFill(column - 1, row, image, color, searchColor); // move top 
        floodFill(column + 1, row, image, color, searchColor); // move bottom 
        floodFill(column, row + 1, image, color, searchColor); // move right 
        floodFill(column, row - 1, image, color, searchColor); // move left 
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        floodFill(sc, sr, image, color, image[sr][sc]);
        
        return image;
    }
};