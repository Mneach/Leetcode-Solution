/*

How to solve the problem : 

0 -> 0
1 -> 01
2 -> 0110

       0
     /   \
    0     1
   / \   / \ 
  0   1 1   0
K 1   2 3   4

# Using DFS
1. Base case -> N == 1, return 0
2. Recursive Case
   - if K % 2 == 0
     - if recursive(N - 1, (K / 2)) == 0 ? return 1 : return 0
   - else if K % 2 == 1
     - if recursive(N - 1, (K + 1) / 2) == 0 ? return 0 : return 1

Time Complexity : O(N)

Memory Complexity : O(N) 

*/

class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) {
            return 0;
        }

        if (k % 2 == 0) {
            int result = kthGrammar(n - 1, (k / 2));
            
            if (result == 0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            int result = kthGrammar(n - 1, (k + 1) / 2);

            if (result == 0) {
                return 0;
            } else {
                return result;
            }
        }
    }
};