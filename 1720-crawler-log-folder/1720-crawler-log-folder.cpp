/*

How to solve the problem

# Using two pointer
1. initialize variables
   - left = 0
   - right = 0
   - result = 0
2. loop from the first index of logs array until last index of logs array
   - if logs != "../"
     - logs[left] = logs[right]
     - increase the left pointer
     - increase the right pointer
   - else
     - decreaes the left pointer until left == 0 or logs[left] != "./"
3. loop from index 0 until left pointer to get the answer
   - if logs[left] == "./"
     - then skip the count
4. return the result

Time Complexity : O(N + M)
N -> size of logs
M -> loop from the index 0 until left pointer to get the result

Memory Compelxity : O(1)

*/

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int result = 0;
        int left = 0;
        int right = 0;

        while (right < logs.size()) {
            if (logs[right] != "../") {
                logs[left] = logs[right];
                left++;
            } else {
                left = max(0, left - 1);
                while (left > 0 && logs[left] == "./") {
                    left--;
                }
            }

            right++;
        }

        for (int i = 0; i < left; i++) {
            if (logs[i] != "./") {
                result++;
            }
        }

        return result;
    }
};