
/*

How to solve the problem

# Using brute force solution
1. loop for every row in the matrix
  - loop for every col in the matrix
    - if matrix[row][col] == target, then return true
2. return false

Time Complexity : O(N * M)
N -> total row
M -> total col

Memory Complexity : O(1)

# Using Binary Search
1. initialize variables
   - n = matrix.size()
   - m = matrix[0].size()
   - left = 0
   - right = (n * m) - 1
2. while left <= right (binary serach algorithm)
   - mid = left + (right - left) / 2
   - row = mid / m
   - col = mid - (row * m)
   - if (matrix[row][col] < target) 
     - right = mid - 1
   - else if (matrix[row][col] > target)
     - left = mid + 1
   - else
     - return true
3. return false

Time Complexity : O(log N * M)
N -> total row
M -> total col

Memory Complexity : O(1)


*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0;
        int right = (n * m) - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int row = mid / m;
            int col = mid - (row * m);

            if (matrix[row][col] < target) {
                left = mid + 1;
            } else if (matrix[row][col] > target) {
                right = mid - 1;
            } else {
                return true;
            }
        }

        return false;
    }
};