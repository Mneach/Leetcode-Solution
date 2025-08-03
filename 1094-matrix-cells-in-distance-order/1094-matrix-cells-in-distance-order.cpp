class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int r0, int c0) {
        vector<vector<int>> cells;
        cells.reserve(rows * cols);
        
        // Generate all cells
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                cells.push_back({r, c});
            }
        }
        
        // Sort by Manhattan distance
        sort(cells.begin(), cells.end(), [r0, c0](const vector<int>& a, const vector<int>& b) {
            return abs(a[0] - r0) + abs(a[1] - c0) < abs(b[0] - r0) + abs(b[1] - c0);
        });
        
        return cells;
    }
};