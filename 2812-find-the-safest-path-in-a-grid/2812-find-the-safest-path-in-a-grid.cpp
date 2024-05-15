
// Define the Cell class
class Cell {
public:
    int column;
    int row;
    int value;

    // Constructor
    Cell(int r, int c, int v) : row(r), column(c), value(v) {}
};

struct CompareCell {
    bool operator()(const Cell& a, const Cell& b) {
        return a.value < b.value; 
    }
};


class Solution {
public:
    
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& arr, int row, int column, int i, int j){
        if(row < 0 || row == grid.size()){
            return;
        }
        
        if(column < 0 || column == grid[0].size()){
            return;
        }
        
        // calculate manhattan distance
        int md = abs(row - i) + abs(column - j);
        
        // update the safeness factor
        if(arr[row][column] > md){
            arr[row][column] = md;
            
            // do dfs to adjecent cell
            
            dfs(grid, arr, row - 1, column, i , j); // move top
            dfs(grid, arr, row + 1, column, i , j); // move bottom
            dfs(grid, arr, row, column - 1, i , j); // move left
            dfs(grid, arr, row, column + 1, i , j); // move right
        }
        
        return;
    }
    
    bool isValid(vector<vector<bool>>& visited, int row, int column){
        if(row < 0 || row == visited.size()){
            return false;
        }
        
        if(column < 0 || column == visited[0].size()){
            return false;
        }
        
        if(visited[row][column]){
            return false;
        }
        
        return true;
    }
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        int answer = INT_MAX;
        int totalRow = grid.size();
        int totalColumn = grid[0].size();
    
        vector<vector<int>> arr(totalRow, vector<int>(totalColumn, INT_MAX));
        vector<vector<bool>> visited(totalRow, vector<bool>(totalColumn, false));
        
        // marking safeness factor
        for(int i = 0; i < totalRow; i++){
            for(int j = 0; j < totalColumn; j++){
                if(grid[i][j] == 1){
                    dfs(grid, arr, i, j, i, j);
                }
            }
        }
        
//         for(int i = 0; i < totalRow; i++){
//             for(int j = 0; j < totalColumn; j++){
//                 cout << arr[i][j] << " ";
//             }
            
//             cout << endl;
//         }        
        
        // do bfs from (0,0) to (n - 1 , n - 1)
        // rule : alwasy take the maximum safeness factor
        
        priority_queue<Cell, vector<Cell>, CompareCell> pq;
        
        pq.push(Cell(0, 0, arr[0][0]));
        visited[0][0] = true;
        
        int dx[] = { -1, 0, 1, 0 };
        int dy[] = { 0, 1, 0, -1 };
        
        while(pq.empty() == false){
            Cell currentCell = pq.top();
            pq.pop();
            answer = min(answer, currentCell.value);
            
            if(currentCell.row == totalRow - 1 && currentCell.column == totalColumn - 1){
                break;
            }
            
            // move 4 direction
            for(int i = 0; i < 4; i++){
                int nextCurrentCellX = currentCell.row + dx[i];
                int nextCurrentCellY = currentCell.column + dy[i];
                
                if(isValid(visited, nextCurrentCellX, nextCurrentCellY)){
                    // cout << nextCurrentCellX << " " << nextCurrentCellY << " " << arr[nextCurrentCellX][nextCurrentCellY] << endl;
                    visited[nextCurrentCellX][nextCurrentCellY] = true;
                    pq.push(Cell(nextCurrentCellX, nextCurrentCellY, arr[nextCurrentCellX][nextCurrentCellY]));
                }
            }
            
            // cout << endl;
        }
        
        
        return answer;
    }
};