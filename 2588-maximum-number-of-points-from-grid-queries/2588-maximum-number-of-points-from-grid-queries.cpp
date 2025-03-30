// Represents a cell in the grid with row index, column index, and value
struct Cell {
    int row, col, value;
    Cell(int r, int c, int v) : row(r), col(c), value(v) {}
    bool operator<(const Cell& other) const { return value < other.value; }
};

// Represents a query with its original index and value
struct Query {
    int index, value;
    Query(int i, int v) : index(i), value(v) {}
    bool operator<(const Query& other) const { return value < other.value; }
};

class UnionFind {
private:
    vector<int> parent, size;
public:
    UnionFind(int n) : parent(n, -1), size(n, 1) {}
    
    int find(int node) {
        return (parent[node] < 0) ? node : (parent[node] = find(parent[node]));
    }
    
    bool unionNodes(int nodeA, int nodeB) {
        int rootA = find(nodeA), rootB = find(nodeB);
        if (rootA == rootB) return false;
        if (size[rootA] > size[rootB]) swap(rootA, rootB);
        parent[rootA] = rootB;
        size[rootB] += size[rootA];
        return true;
    }
    
    int getSize(int node) { return size[find(node)]; }
};

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int rowCount = grid.size(), colCount = grid[0].size();
        int totalCells = rowCount * colCount;
        
        vector<Query> sortedQueries;
        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.emplace_back(i, queries[i]);
        }
        sort(sortedQueries.begin(), sortedQueries.end());
        
        vector<Cell> sortedCells;
        for (int row = 0; row < rowCount; row++) {
            for (int col = 0; col < colCount; col++) {
                sortedCells.emplace_back(row, col, grid[row][col]);
            }
        }
        sort(sortedCells.begin(), sortedCells.end());
        
        UnionFind uf(totalCells);
        vector<int> result(queries.size());
        int cellIndex = 0;
        
        constexpr int ROW_DIRECTIONS[] = {0, 0, 1, -1};
        constexpr int COL_DIRECTIONS[] = {1, -1, 0, 0};
        
        for (const auto& query : sortedQueries) {
            while (cellIndex < totalCells && sortedCells[cellIndex].value < query.value) {
                int row = sortedCells[cellIndex].row, col = sortedCells[cellIndex].col;
                int cellId = row * colCount + col;
                
                for (int i = 0; i < 4; i++) {
                    int newRow = row + ROW_DIRECTIONS[i], newCol = col + COL_DIRECTIONS[i];
                    if (newRow >= 0 && newRow < rowCount && newCol >= 0 && newCol < colCount &&
                        grid[newRow][newCol] < query.value) {
                        uf.unionNodes(cellId, newRow * colCount + newCol);
                    }
                }
                cellIndex++;
            }
            result[query.index] = (query.value > grid[0][0]) ? uf.getSize(0) : 0;
        }
        return result;
    }
};