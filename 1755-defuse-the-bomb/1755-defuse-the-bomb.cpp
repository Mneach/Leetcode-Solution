/*

How to solve the problem
1. if k == 0
   - loop from the first index of the array until last index of the array
   - change results[i] = 0
2. else if k > 0
   - loop from index 1 until code + k
     - if (right - left) + 1 == k
       - put the total value into the results array
       - decrease total value by code[left]
       - increaes left pointer
    - add total value by right pointer % size of code array
    - increase right pointer 
3. else 
   - loop from index code.size() - k until code.size() * 2 - 1
     - if (right - left) + 1 == k
       - put the total value into results array
       - decrease total value by code[left]
       - increase left pointer
    - add total value by right pointer % size of code array
    - increase right pointer
4. return results array

Time Complexity : O(N + K)
N -> size of code arrays

Memory Complexity : O(1)


*/

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int left = 0;
        int right = 0;
        int total = 0;
        vector<int> results;

        if (k == 0) {
            for (int i = 0; i < code.size(); i++) {
                results.push_back(0);
            }
        } else if (k > 0) {
            left = 1;
            right = 1;

            while (right < code.size() + k) {
                
                total += code[right % code.size()];

                if ((right - left) + 1 == k) {
                    results.push_back(total);
                    total -= code[left % code.size()];
                    left++;
                }
                right++;
            }
        } else {
            k = abs(k);
            left = code.size() - k;
            right = code.size() - k;

            while (right < code.size() * 2 - 1) {
                total += code[right % code.size()];

                if ((right - left) + 1 == k) {
                    results.push_back(total);
                    total -= code[left % code.size()];
                    left++;
                }

                right++;
            }
        }

        return results;
    }
};