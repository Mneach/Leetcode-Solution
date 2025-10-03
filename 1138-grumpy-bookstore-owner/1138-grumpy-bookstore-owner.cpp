/*

How to solve the problem : 
1. initialize variables (count = 0, result = 0)
2. loop from the first index of the array until the last index of the array
   - if grumpy[i] == 0, then add county by customers[i]
   - if grumpy[i] == 1, add count by customers[i]
   - if i >= minutes && grumpy[i - minutes] == 1
     - decrease count by customers[i - minutes] 
   - get the maximum result (result = max(result, count))

Time Complexity : O(N)
N -> size of grumpy array

Memory Complexity : O(1)

*/

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int count = 0;
        int secret = 0;
        int maxSecret = 0;

        for (int i = 0; i < grumpy.size(); i++) {
            if (grumpy[i] == 0) {
                count += customers[i];
            } else {
                secret += customers[i];
            }

            if (i >= minutes && grumpy[i - minutes] == 1) {
                secret -= customers[i - minutes];
            }

            maxSecret = max(secret, maxSecret);

        }

        return count + maxSecret;
    }
};