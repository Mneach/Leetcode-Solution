class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> result(n, vector<char>(m, '.'));

        // Rotate the box 90° clockwise
        for (int i = 0; i < m; i++) {
            int empty = n - 1;
            for (int j = n - 1; j >= 0; j--) {
                if (box[i][j] == '#') {
                    result[empty--][m - 1 - i] = '#';
                } else if (box[i][j] == '*') {
                    result[j][m - 1 - i] = '*';
                    empty = j - 1;
                }
            }
        }
        return result;
    }
};
