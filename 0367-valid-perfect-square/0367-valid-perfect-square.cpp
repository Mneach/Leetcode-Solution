/*

# Brute Force Solution

# Simulation

num = 17

currentNumber = 4
currentNumber * currentNumber = 5 * 5 = 25

# Pseudocode
1. initialize variables
   - currentNumber = 1
2. while currentNumber * currentNumber <= num
   - if currentNumber * currentNumber == num
     - return true
   - else
     - increase the current number by 1
3. return false

Time Complexity : O(sqrt(num))

Memory Complexity : O (1)

# Binary Search

# Simulation
num = 17

left = 5
right = 4
mid = 4

mid * mid = 4 * 4 = 16

if mid * mid == num
- then return true
else if mid * mid > num
- right = mid - 1
else
- left = mid + 1

# Pseudocode
1. initialize variables
   - left = 0
   - right = num
2. while <= right (do binary search algorithm)
   - mid = left + (right - left) / 2
   - result = mid * mid
   - if result == num
     - return true
   - else if result > num
     - right = mid - 1
   - else
     - left = mid + 1
3. return false

Time complexity : O(log N)
N -> num

Memory complexity : O (1)

*/


class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1;
        int right = num;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long result = 1LL * mid * mid;

            if (result == num) {
                return true;
            } else if (result > num) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return false;
    }
};