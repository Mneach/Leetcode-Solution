
/*

# Brute Force Solution

# Simulation

First Simulation

n = 3
row 1 = 1
row 2 = 2


Second Simulation
n = 12

row 1 = 1
row 2 = 2
row 3 = 3
row 4 = 4
row 5 = 2

total coin = 10

# Pseudocode
currentRow = 1
1. loop while n >= currentRow
   n -= currentRow
   currentRow++
2. return current row

Time Complexity : O(M)
M -> total complete row

Memory Complexity : O(1)

# Using binary search

# Simulation

N = 12
formula to get total coin at row x : currentRow * (currentRow + 1) / 2

left = 5
right = 4
mid = 4

result = max(result, mid) = 4

if we take 5 complete row how many coins that we need 
total coin that we need = 5 * (5 + 1) / 2 = 15

# Pseudocode
1. Initialize variables
   - left = 1
   - right = n
   - result = 0
2. while left <= right (binary search algorithm)
   - mid = left + (right - left) / 2
   - totalCoin = mid * (mid + 1) / 2
   - if totalCoin <= n
     - result = max(result, mid)
     - left = mid + 1
   - else
     - right = mid - 1
3. return the result

Time Complexity : O (log N)

Memory Complexity : O (1)

*/

class Solution {
public:
    int arrangeCoins(int n) {
        int left = 1;
        int right = n;
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long totalCoin = (1LL * mid * (mid + 1)) / 2;
            
            if (totalCoin <= n) {
                left = mid + 1;
                result = max(result, mid);
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};