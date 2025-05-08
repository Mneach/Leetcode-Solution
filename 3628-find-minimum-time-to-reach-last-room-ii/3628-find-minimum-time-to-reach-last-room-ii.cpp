struct Position {
    int row;
    int col;
    int distance;
    
    Position(int r, int c, int d) : row(r), col(c), distance(d) {}
};

class Solution {
    static constexpr int INF = 0x3f3f3f3f;
    static constexpr int DIRECTIONS[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        if (moveTime.empty() || moveTime[0].empty()) return 0;
        
        const int rows = moveTime.size();
        const int cols = moveTime[0].size();
        
        vector<vector<int>> distances(rows, vector<int>(cols, INF));
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        auto comparator = [](const Position& a, const Position& b) {
            return a.distance > b.distance;
        };
        
        priority_queue<Position, vector<Position>, decltype(comparator)> pq(comparator);
        
        // Start from top-left corner
        distances[0][0] = 0;
        pq.emplace(0, 0, 0);
        
        while (!pq.empty()) {
            Position current = pq.top();
            pq.pop();
            
            // Skip if already visited or reached destination
            if (visited[current.row][current.col]) continue;
            if (current.row == rows - 1 && current.col == cols - 1) break;
            
            visited[current.row][current.col] = true;
            
            // Explore all four directions
            for (const auto& dir : DIRECTIONS) {
                int newRow = current.row + dir[0];
                int newCol = current.col + dir[1];
                
                if (!isValidPosition(newRow, newCol, rows, cols)) continue;
                
                int newDistance = calculateNewDistance(
                    current.row, current.col, newRow, newCol, 
                    distances[current.row][current.col], 
                    moveTime[newRow][newCol]
                );
                
                if (newDistance < distances[newRow][newCol]) {
                    distances[newRow][newCol] = newDistance;
                    pq.emplace(newRow, newCol, newDistance);
                }
            }
        }
        
        return distances[rows - 1][cols - 1];
    }
    
private:
    bool isValidPosition(int row, int col, int totalRows, int totalCols) const {
        return row >= 0 && row < totalRows && col >= 0 && col < totalCols;
    }
    
    int calculateNewDistance(int currentRow, int currentCol, 
                           int newRow, int newCol,
                           int currentDistance, int moveCost) const {
        // The original distance calculation logic
        return max(currentDistance, moveCost) + (currentRow + currentCol) % 2 + 1;
    }
};