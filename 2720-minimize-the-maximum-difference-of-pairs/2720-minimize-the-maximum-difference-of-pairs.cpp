
/*

# Brute Force Solution

# Simulation
[10,1,2,7,1,3] p = 2

minimumX = 0, maximumX = 9

x = 0
|nums[i] - nums[j]| <= 0, we need to find p pairs

    I
          J
[10,1,2,7,1,3]

pair 1 = 1,4

=====================
x = 1
|nums[i] - nums[j]| <= 1, we need to find p pairs

[10,1,2,7,1,3]

pair 1 = 1,4 = |nums[i] - nums[4]| = 0
pair 2 = 2,3 = |nums[i] - nums[4]| = 1

max (pair 1, pair 2) = 1

# Pseudocode
1.	initialize variables
   - minimumX = 1
   - maximumX = max number in nums array
   - result = 0
2. loop from minimumX until maximumX
   - check if the current x can create p pairs
     - totalPairs = 0
     - visited array = hashTable
     - loop for every element in nums array
       - if index i already visited, then skip
       - get nums[i]
         - loop for every element in nums array start from i + 1
           - if index j already visited, then skip
           - get nums[j]
           - if |nums[i] - nums[j]| <= x
             - then add totalPairs by 1
             - mark index i and j into the visited array
     - if totalPairs == p
       - result = x
       - break
3. return the result

Time Complexity : O(x * n * n) = O(x * N^2)
x -> max number in nums array
n -> size of nums array

Memory Complexity : O(N)
N -> size of nums array

# Binary Search

# Simulation

[10,1,2,7,1,3] p = 2

minimumX = 0 
maximumX = 9
x = 4

find nums[i] - nums[j] <= x, we need to find p pairs

[10,1,2,7,1,3]

pair 1 = 10 7
pair 2 = 1 1
pair 3 = 2 3

[10,1,2,7,1,3] p = 2

=======================
minimumX = 0
maximumX = 3
x = 1

find nums[i] - nums[j] <= x, we need to find p pairs

[10,1,2,7,1,3]

pair 1 = 1 1
pair 2 = 2 3

max = (pair 1, pair 2) = 1

# Pseudocode
1.	initialize variables
   - minimumX = 1
   - maximumX = max number in nums array
   - result = 0
2. while minimumX <= maximumX
   - x = minimumX + (maximumX - minimumX) / 2
   - check if the current x can create p pairs
     - totalPairs = 0
     - visited array = hashTable
     - loop for every element in nums array
       - if index i already visited, then skip
       - get nums[i]
         - loop for every element in nums array start from i + 1
           - if index j already visited, then skip
           - get nums[j]
           - if |nums[i] - nums[j]| <= x
             - then add totalPairs by 1
             - mark index i and j into the visited array
     - if totalPairs <= p
       - result = x
       - minimumX = x + 1
     - else
       - maximumX = x - 1
3. return the result

Time Complexity : O(log x * n * n) = O(log x * N^2)
x -> max number in nums array
n -> size of nums array

Memory Complexity : O(N)
N -> size of nums array


# Binary Search + Sorting

       I
[1,2,2,4], p = 1

minimumX = 0
maximumX = 1
x = 2
result = 0

find |nums[i] - nums[j]| <= 0, we want to find 1 pair

pair 1 = 2 2

# Pseudocode

1.	sort nums array in asc order
2.	initialize variables
   - minimumX = 1
   - maximumX = max number in nums array
   - result = 0
3. while minimumX <= maximumX
   - x = minimumX + (maximumX - minimumX) / 2
   - check if the current x can create p pairs
     - totalPairs = 0
     - loop for every elements in nums array (loop from index 0 until size of nums array - 1)
       - if abs(nums[i] - nums[i + 1] <= x
         - totalPairs++
       - if totalPairs == p, then break the loop
     - if totalPairs < p
       - minimumX = x + 1
     - else
       - result = x
       - maximumX = x - 1
         
4. return the result

Time Complexity : O (N log N + log X * N)
N log N -> sorting algorithm
log X * N -> to find a valid x value

Memory Complexity : O(N)
N -> sorting algorithm

*/

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int minimumX = 0;
        int maximumX = nums[nums.size() - 1];
        int result = INT_MAX;

        while (minimumX <= maximumX) {
            int x = minimumX + (maximumX - minimumX) / 2;

            // check if x is a valid result
            int totalPairs = 0;
            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i + 1] - nums[i] <= x) {
                    totalPairs++;
                    i++;
                }
            }

            if (totalPairs < p) {
                minimumX = x + 1;
            } else {
                result=  x;
                maximumX = x - 1;
            }
        }

        return result;
    }
};