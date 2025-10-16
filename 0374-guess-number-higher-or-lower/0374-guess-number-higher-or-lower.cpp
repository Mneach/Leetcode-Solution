/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

 /*

How to solve the problem

# Brute force solution
1. loop 1 until n
   - call guess function and passing current number as parameter
   - if the function return 0, then we need to return the current number

Time Complexity : O(N)
N -> total number

# Can we improve the solution ? 
1. Yes we can, instead of using linear search to guess the number, we can use binary search to guess the number


# Binary search
1. initialize variables
   - left = 1
   - right = n
   - result = -1
2. while left <= right (binary search algorithm)
   - get mid value
   - if guessNumber(mid) == 0
     - result = mid
     - break
   - else if guessNumber(mid)  == -1
     - right = mid - 1
   - else
     - left = mid + 1
3. return result

 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (guess(mid) == 0) {
                result = mid;
                break;
            } else if (guess(mid) == -1) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};