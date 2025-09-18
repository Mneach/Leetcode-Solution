/*

How to solve the problem : 
1. initialize bucket array with size n^2 and default value = 0
2. loop for every number in grid array
3. put those numbers in bucket array
   - bucket[number - 1]++;
4. loop from first index of bucket array until last index of bucket array
   - if bucket[i] == 0, that means i + 1 is missing
   - if bucket[i] == 2, that means i + 1 repeated

Time Complexity : O(N^2)
N -> size of grid

Memory Complexity : O(N^2)
N -> size of grid / bucket array

*/


class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int size = grid.size();
        vector<int> bucket(size * size, 0);

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                int number = grid[i][j];

                // because index start from 0
                bucket[number - 1]++;
            }
        }

        int missing = -1;
        int repeated = -1;
        for (int i = 0; i < bucket.size(); i++) {
            if (bucket[i] == 0) {
                missing = i + 1;
            } else if (bucket[i] == 2) {
                repeated = i + 1;
            }
        }

        return {repeated, missing};
    }
};