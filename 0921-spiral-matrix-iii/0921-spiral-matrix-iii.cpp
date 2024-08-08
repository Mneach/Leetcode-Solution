class Solution {
public:

    bool beetween(int rows, int cols, int nextRow, int nextCol){
        return nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols;
    }

    vector<vector<int>> spiralMatrixIII(int rows, int cols, int row, int col) {
        int totalVisited = rows * cols;
        
        vector<vector<int>> answer;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        visited[row][col] = true;
        totalVisited--;

        answer.push_back({row, col});
        
        // move
        // 0 = top
        // 1 = right
        // 2 = bottom
        // 3 = left
        int move = 1;
        int count = 20;
        while(totalVisited != 0){
            count--;
            int nextRow = row;
            int nextCol = col;
            // cout << count << " " << nextRow << " " << nextCol << " " << move << endl;
            if(move == 0){
                nextRow--;
            }else if(move == 1){
                nextCol++;
            }else if(move == 2){
                nextRow++;
            }else{
                nextCol--;
            }
            
            // already visited
            if(beetween(rows, cols, nextRow, nextCol) && visited[nextRow][nextCol] == true){
                // keep direction
                move = move - 1;
                if(move < 0) move = 3;
                
            }else if(beetween(rows, cols, nextRow, nextCol)){
                // change direction
                move = (move + 1) % 4;
                visited[nextRow][nextCol] = true;
                answer.push_back({nextRow, nextCol});
                row = nextRow;
                col = nextCol;
                totalVisited--;
            }else{
                row = nextRow;
                col = nextCol;
                move = (move + 1) % 4;
            }
            
        }

        

        return answer;
    }
};