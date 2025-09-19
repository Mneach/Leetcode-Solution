/*

How to solve the problem : 
1. create another array that contain all of the numbers in heights array
2. sort the new array asc order
3. loop from the first index of heights until last index of heights, compare new array[i] with the heights[i], if the result is not equal, then increase the result value by 1

Time Complexity : O(N log N + N)
N -> size of heights / new array
N log N -> sorting algorithm time complexity
last N -> loop from first index of heights until last index of heights

Memory Complexity : O(N)
N -> size of new array

*/

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int result = 0;
        vector<int> newArray;

        for (auto height : heights) {
            newArray.push_back(height);
        }

        sort(newArray.begin(), newArray.end());

        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != newArray[i]) {
                result++;
            }
        }

        return result;
    }
};