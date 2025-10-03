/*

How to solve the problem

# Using sliding window
1. initialize the first valid index (validIndex = colors.size() * 2)
2. initialize count variable (count = 0)
3. while ((index - k) + 1 <= validIndex)
   - if (colors[index % size] == colors[(index + 1) % size])
     - count = 0
   - else
     - count++
   - if (count >= k - 1)
     - result++
     - if (validIndex == size * 2)
       - update valid index -> validIndex = (index - k) + 1 + size 
   - index++;

Time Complexity : O(N + K) -> O(N)
N -> size of colors

Memory Complexity : O(1)

*/

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int size = colors.size();
        int count = 0;
        int result = 0;
        int index = 0;
        int validIndex = size * 2;

        while ((index - k) + 1 < validIndex) {
            if (colors[index % size] == colors[(index + 1) % size]) {
                count = 0;
            } else {
                count++;
            }

            if (count >= k - 1) {
                result++;
                if (validIndex == size * 2) {
                    validIndex = (index - k) + 1 + size;
                }
            }

            index++;
        }

        return result;
    }
};