
/*

How to solve the problem : 

# Using Sliding Window
1. initialize left, right, count, and result (left = 0, right = 0, count = k, result = k)
2. loop from the first index of blocks string until the last index of blocks strings
   - if blocks[right] == 'W'
     - if (count == k) count = 1
     - else count++
   - if (right - left) + 1 == k
     - result = min(result, count)
     - if (blocks[left] == 'W') count--
     - increase left pointer by 1
   - right++

Time Complexity : O(N)
N -> length of blocks string

Memory Complexity : O(1)

*/

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int left = 0;
        int right = 0;
        int count = 0;
        int result = k;

        while(right < blocks.length()) {
            if (blocks[right] == 'W') {
                count++;
            }

            if ((right - left) + 1 == k) {
                result = min(result, count);
                
                if (blocks[left] == 'W') {
                    count--;
                }
                left++;
            }

            right++;
        }

        return result;
    }
};