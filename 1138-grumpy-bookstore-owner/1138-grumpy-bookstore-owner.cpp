/*

How to solve the problem : 
1. initialize variables (count = 0, result = 0)
1. Loop from the first index of the array until the last index of the array
2. add customers[i] to the count variable
3. if (i >= minutes)
   - if (grumpy[i - minutes] == 1)
     - decrease count by customers[i - minutes]
4. get the maximum count value (result = max(result, count))

Time Complexity : O(N)
N -> size of grumpy array

Memory Complexity : O(1)

*/

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int count = 0;
        int result = 0;

        for (int i = 0; i < grumpy.size(); i++) {
            if (grumpy[i] == 0) {
                count += customers[i];
            }
        }

        for (int i = 0; i < grumpy.size(); i++) {
            if (grumpy[i] == 1) {
                count += customers[i];
            }

            if (i >= minutes && grumpy[i - minutes] == 1) {
                count -= customers[i - minutes];
            }

            result = max(result, count);
        }

        return result;
    }
};