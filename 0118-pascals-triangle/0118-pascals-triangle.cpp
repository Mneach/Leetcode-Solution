/*

How to solve the problem : 
1. use row 1 as a basecase
2. every time we add a new row, put 1 at left and right side as a default value
3. sum the number from previous row and put that result in the new row 

Time Complexity : O(N ^ 2)
N -> total number in that pascal triangle

Memory Complexity : O(N ^ 2)
N -> total number in that pascal triangle

*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> array;

        // basecase
        array.push_back({1});
        numRows--;

        while (numRows > 0) {
            vector<int> lastRow = array[array.size() - 1];
            vector<int> newRow;
            newRow.push_back({1});

            for (int i = 1; i < lastRow.size(); i++) {
                newRow.push_back(lastRow[i] + lastRow[i - 1]);
            }

            newRow.push_back({1});

            array.push_back(newRow);
            numRows--;
        }

        return array;
    }
};