class Solution {
public:
    
    void floodFill(int column, int row, vector<vector<int>>& image, int color, int searchColor, vector<vector<bool>>& visit){
        
        if(row < 0 || column < 0) return;
        else if(row == image.size() || column == image[0].size()) return;
        else if(image[row][column] != searchColor) return;
        else if(visit[row][column]) return;
        
        image[row][column] = color;
        visit[row][column] = true;
        
        floodFill(column - 1, row, image, color, searchColor, visit); // move top 
        floodFill(column + 1, row, image, color, searchColor, visit); // move bottom 
        floodFill(column, row + 1, image, color, searchColor, visit); // move right 
        floodFill(column, row - 1, image, color, searchColor, visit); // move left 
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        vector<vector<bool>> visit(image.size(), vector<bool>(image[0].size(), false)); 
        floodFill(sc, sr, image, color, image[sr][sc], visit);
        
        return image;
    }
};