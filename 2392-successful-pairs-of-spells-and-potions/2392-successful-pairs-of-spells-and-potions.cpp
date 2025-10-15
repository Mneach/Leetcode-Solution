/*

How to solve the problem

# Using Brute force solution
1. loop for every element in spells array
   - result = 0
   - loop for every element in potions array
      - if (spells[i] * potions[j] > success) 
        - add result by 1
   - push result into the results array
2. return the results array

Time Compelxity : O(N * M)
N -> size of spells
M -> size of potions

Memory Complexity : O(K)
K -> size of results array

# Using binary search
1. initialize variables
   - vector<int> results
2. sort potions array in asc
3. loop for every element in spells array
   - find most right index of j, where spells[i] * potions[j] <= success (use binary search)
   - result = potions.size() - resultBinarySearch - 1
   - push the result into the results variable
4. return the results array

Time Complexity : O(N * log M + M log M)
N -> size of spells array
M -> size of potions array

Memory Complexity : O(K)
K -> size of results array

*/


class Solution {
private:
    int binarySearch(vector<int>& potions, long long success, int spell) {
        int left = 0;
        int right = potions.size() - 1;
        int binarySearchResult = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (1LL * spell * potions[mid] < success) {
                left = mid + 1;
                binarySearchResult = mid;
            } else {
                right = mid - 1;
            }
        }

        return binarySearchResult;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> results;

        sort(potions.begin(), potions.end());

        for (int i = 0; i < spells.size(); i++) {
            int spell = spells[i];

            // do binary search
            int binarySearchResult = binarySearch(potions, success, spell);
            int result = potions.size() - binarySearchResult - 1;
            results.push_back(result);
        }

        return results;
    }
};