/*

# Observation
⦁	x represent the maximum number of products given to any store
⦁	We need to distribute all of the products
⦁	A store can only be given at most one product type but can be given any amount of it.
⦁	We want x as small as possible.
 
# Brute Force Solution
n = 6, quantities = [11,6]

minimumX = 1
maximumX = max quantity in quantities array

    I
[11,6]

x = 3
current quantity = 3

store 1 = 3
store 2 = 3
store 3 = 3
store 4 = 2
store 5 = 3
store 6 = 3

result = min(store 1 - 6) = 2

==============
n = 7, quantities = [15,10,10]

minimumX = 1
maximumX = 15

       I
[15,10,10]

x = 6
current quantity = 

store 1 = 6
store 2 = 6
store 3 = 3
store 4 = 6
store 5 = 4
store 6 = 6  
store 7 = 4

result = max(store 1 - 7) = 5

# Pseudocode
1.	initialize variables
   - minimumX = 1
   - maximumX = max quantity in quantites array
   - result = 0
2. loop from minimumX until maximumX
   - check if x is a valid answer
     - index = 0
     - totalStore = 0
     - while index < quantities array size && totalStore <= n
       - if currentQuantity % x == 0
         - totalStore += currentQuantity / x
       - else
         - totalStore += (currentQuantity / x) + 1
       - index++
     - if totalStore == n
      - result = x
      - break
3. return the x value

Time Complexity : O(M + X * M)
X -> maximum x value
M -> size of quantites array

Memory Complexity : O(1)


# Binary Search

# Simulation
n = 7, quantities = [15,10,10]

minimumX = 5
maximumX = 4
x = minimumX + (maximumX - minimumX) / 2
x = 5

       I
[15,10,10]

current quantity = 10

if currentQuantity % x == 0
⦁	totalStore += currentQuantity / x
else
⦁	totalStore += (currentQuantity / x) + 1

total store = 7

store 1 = 6
store 2 = 6
store 3 = 3
store 4 = 6
store 5 = 4
store 6 = 6
store 7 = 4

result = max(store 1 - 7) = x = 5

# Pseudocode
1.	initialize variables
   - minimumX = 1
   - maximumX = max quantity in quantites array
   - result = 0
2. while minimumX <= maximumX (do binary search algorithm)
   - x = minimumX + (maximumX - minimumX) / 2
   - check if x is a valid answer
     - index = 0
     - totalStore = 0
     - while index < quantities array size && totalStore <= n
       - if currentQuantity % x == 0
         - totalStore += currentQuantity / x
       - else
         - totalStore += (currentQuantity / x) + 1
       - index++
     - if totalStore <= n
      - result = x
      - maximumX = x - 1
     - else
      - minimumX = x + 1
3. return the x value

Time Complexity : O(M + log X * M)
X -> max quantity in quantites array
M -> size of quantities array

Memory Complexity : O(1)   

*/

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int minimumX = 1;
        int maximumX = *max_element(quantities.begin(), quantities.end());
        int result = -1;

        while (minimumX <= maximumX) {
            int x = minimumX + (maximumX - minimumX) / 2;

            // check x is a valid answer
            int totalStore = 0;
            int index = 0;

            while (index < quantities.size() && totalStore <= n) {
                int quantity = quantities[index]; 
                if (quantity % x == 0) {
                    totalStore +=  quantity / x;
                } else {
                    totalStore += (quantity / x) + 1;
                }

                index++;
            }

            if (totalStore <= n) {
                result = x;
                maximumX = x - 1;
            } else {
                minimumX = x + 1;
            }
        }

        return result;
    }
};