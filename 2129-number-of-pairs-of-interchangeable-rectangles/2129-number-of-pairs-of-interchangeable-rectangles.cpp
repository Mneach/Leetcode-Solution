/*

How to solve the problem : 

# Bructe Force Solution
1. Loop for every rectacngle in rectangles array
   - get the heigh and width
   - get the result, where result = height / width
   - loop from first index of rectangles until last index of rectangles
     - we need to count how many rectangle that have the same divison result with the current rectangle
    
Time Complexity : O(N^2)
N -> size of rectangles array

Memory Compleixty : O(1)

What makes the algorithm run slower ? 
1. for every rectangle we need to loop again from first index of rectangles until last index of rectangles to get the answer in the index i

# Hashtable approach
1. Construct hashtble with key = [height / width], value = total (height / width) appear in rectangles array
2. To construct the hashtable, we need to loop from first index of array until last index of array
3. To get the current answer we just need to add hashtable[height / width] to the answer value
4. Put the current result (height / width) into the hashtable, 

Time Complexity : O(N)
N -> size of rectangles array

Memory Complexity : O(M)
M -> size of the hashtable

*/

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long answer = 0;
        unordered_map<double, long long> hashTable;

        for (auto rectangle : rectangles) {
            int height = rectangle[0];
            int width = rectangle[1];

            double key = (height * 1.0) / (width * 1.0);

            answer += hashTable[key];
            hashTable[key]++;
        }

        return answer;
    }
};