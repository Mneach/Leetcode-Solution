/*

How to solve the problem

# Using Sliding Window + Hashtable
1. initialize variables
   - hashtable with key = fruits[i] and value = total fruits[i] appears
   - left = 0
   - right = 0
   - result = 0
2. while right < fruits.size()
   - put fruits[right] into the hastable
   - while hashtable size > 2
     - decrease hashtable[fruits[left]] by 1
     - if hashtable[fruits[left]] == 0
       remove the fruits[left] from the hashtable
     - increase left pointer by 1
  - get the result using this formula
    - result = max(result, right - left + 1)
  - increase right pointer by 1

Time Complexity : O(N)
N -> size of fruits array

Memory Complexity : O(M)
M -> total different number in fruits array -> worse case -> 3 numbers

*/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> hashTable;
        int left = 0;
        int right = 0;
        int result = 0;

        while (right < fruits.size()) {
            hashTable[fruits[right]]++;

            while (hashTable.size() > 2) {
                hashTable[fruits[left]]--;

                if (hashTable[fruits[left]] == 0) {
                    hashTable.erase(fruits[left]);
                }
                
                left++;
            }

            result = max(result, (right - left) + 1);
            right++;
        }

        return result;
    }
};