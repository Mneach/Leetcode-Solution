class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> bucket((grid.size() * grid.size()) + 1, 0);
        int repeated = -1;
        int missing = -1;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                int number = grid[i][j];
                bucket[number]++;
            }
        }

        for (int i = 0; i < bucket.size(); i++) {
            if (bucket[i] == 0) missing = i;
            else if (bucket[i] == 2) repeated = i;
        }

        return {repeated, missing};
    }
};