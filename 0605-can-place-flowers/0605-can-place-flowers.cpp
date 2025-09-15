/*

How to solve the problem : 

# Using basic logic
1. loop from left index of flower bed until right index of flower bed
2. for every index we need to do these steps
   1. check if the left index of the current index (index - 1) == 0, then we can mark left as valid
   2. check if the right index of the current index (index + 1) == 0, then we can mark right as valid
   3. if left and right are valid, we can put the flower in that index and change the current value from 0 to 1, otherwise just return false

edge cases : 
1. what if index == 0 ? 
   - if that the case, we can mark left as valid 
2. what if index == flowerbed.size() ? 
   - if that the case we also can mark right as valid

Time Complexity : O(N)
N -> size of flowerbed array

Memory Comlexity : O(1)

*/
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        for (int i = 0; i < flowerbed.size(); i++) {
            bool left = false;
            bool right = false;

            if (flowerbed[i] == 1) {
                continue;
            }

            if (i == 0) {
                left = true;
            } 
            
            if (i == flowerbed.size() - 1) {
                right = true;
            }

            if (i > 0) {
                // check left value
                if (flowerbed[i - 1] == 0) {
                    left = true;
                }
            } 
            
            if (i < flowerbed.size() - 1) {
                if (flowerbed[i + 1] == 0) {
                    right = true;
                }
            }

            if (left && right) {
                n--;
                flowerbed[i] = 1;
            }

            if (n == 0) break;
        }

        return n <= 0;
    }
};