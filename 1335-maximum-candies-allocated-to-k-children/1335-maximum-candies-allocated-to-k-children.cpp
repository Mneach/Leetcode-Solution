/*

How we can solve the problem

# Using Brute force solution
1. initialize variables
   - minimumCandy = 1
   - maximumCandy = get maximum candy in candies array
   - result = 0
2. loop from the minimumCandy until maximumCandy
   - check if the currentCandy can be distributed to the k childs
     - totalChild = 0
     - valid = false
     - loop from every candy in candies array
       - totalChild += candy / currentCandy
       - if totalChild >= k
         - valid = true
         - break the loop 
     - if totalChild >= k
       - mark current candy as our answer (result = max(result, currentCandy))
3. return the result

Time Complexity : O(N * M)
N -> size of candies array
M -> maximum candy in candies array

Memory Complexity : O(1)

# Using binary search
1. initialize variables
   - minimumCandy = 1
   - maximumCandy = get maximum candy in candies array
   - result = 0
2. while minimumCandy <= maximumCandy (do binary search algorithm)
   - currentCandy = minimumCandy + (maximumCandy - minimumCandy) / 2
   - check if the currentCandy can be distributed to the k childs
     - totalChild = 0
     - valid = false
     - loop from every candy in candies array
       - totalChild += candy / currentCandy
       - if totalChild >= k
         - valid = true
         - break the loop 
     - if totalChild >= k
       - mark current candy as our answer (result = max(result, currentCandy))
       - minimumCandy = currentCandy + 1
     - else
       - maximumCandy = currentCandy - 1
3. return the result

Time Complexity : O(N * log M)
N -> size of array
M -> maximum candies in candy array

Memory Complexity : O(1)

*/

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int minimumCandy = 1;
        int maximumCandy = *max_element(candies.begin(), candies.end());
        int result = 0;

        // do binary search algoritm
        while (minimumCandy <= maximumCandy) {
            int currentCandy = minimumCandy + (maximumCandy - minimumCandy) / 2;

            // check if we can distribute current candy to the k childs
            bool valid = false;
            long long totalChild = 0;
            for (int i = 0; i < candies.size(); i++) {
                totalChild += candies[i] / currentCandy;

                if (totalChild >= k) {
                    valid = true;
                    break;
                }
            }

            if (valid) {
                result = max(result, currentCandy);
                minimumCandy = currentCandy + 1;
            } else {
                maximumCandy = currentCandy - 1;
            }
        }

        return result;
    }
};