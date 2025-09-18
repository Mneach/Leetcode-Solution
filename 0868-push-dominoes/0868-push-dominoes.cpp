/*

How to solve the problem : 

# Using two pointer approach
1. Loop from the first index of dominoes array until the last index of dominoes array
2. we will intialize the left and right pointer with value 0
3. if dominoes[i] == 'R'
   - mark flagRight = true
   - totalRight = 0;
   - move the current left pointer to current right
4. if dominoes[i] == 'L'
   - if total R == 0, move to the left pointer until the right pointer and change dominoes[left] = 'L'
   - else
     - move the left pointer to the middle of the distance of right pointer and left pointer
     - if the distance is odd, then change dominoes[i] = '.' and add left pointer by 1
     - move the left pointer until the right pointer and change dominoes[i] = 'L'
   - reset totalRight = 0
   - mark flagRight = false

Time Complexity : O(N)
N -> size of dominoes array

Memory Complexity : O(1)

*/

class Solution {
public:
    string pushDominoes(string dominoes) {
        int left = 0;
        int totalRight = 0;
        bool flagRight = false;

        for (int right = 0; right < dominoes.length(); right++) {

            if (dominoes[right] == 'R') {
                flagRight = true;
                left = right;
            } else if (dominoes[right] == 'L') {
                
                if (flagRight == 0) {
                    while (left <= right) {
                        dominoes[left] = 'L';
                        left++;
                    }
                } else {
                    int length = (right - left) + 1;
                    int middle = left + (length / 2);
                    left = middle;

                    if (length % 2 == 1) {
                        dominoes[middle] = '.';
                        left++;
                    }

                    while (left <= right) {
                        dominoes[left] = 'L';
                        left++;
                    }

                    flagRight = false;
                }
            }

            if (flagRight) {
                dominoes[right] = 'R';
            }
        }

        return dominoes;
    }
};