/*

How to solve the problem : 

# Using hash table + recursive
1. loop for every number in nums array to construct the hash table
2. hash table will have key = number and value = total number that appear in nums array
3. loop for every number in nums array to get the answer
4. for every number, we need to check if hashtable[number + 1] is exists ? 
   - case 1 : hashtable[number + 1] exists, then we will increase the number to number + 1 and repeat step 4
   - case 2 : hashtable[number + 1] not exists, then we will stop the recursive and return 0
   - case 3 : if the number is already cache in cache hash table, we just need directly return that
   - put the result in the cache hash table with key = number and value = result
   - calculate result with this formula : hashTable[number] + recursive()
5. loop for every data in cache hash table and find the largest result

Time Complexity : O(N + N + M) -> O(2N + M) -> O(N)
first N -> to construct the hash table
second N -> to construct the answer
M -> to get the answer from cache table

Memory Complexity : O(N + M) -> O(N)
N -> hash table
M -> cache hash table

*/

class Solution {
private:
    int recursive(unordered_map<int,int> &hashTable, unordered_map<int,int> &cacheHashTable, int number) {

        if (hashTable[number] == 0) {
            return 0;
        }

        if (cacheHashTable[number] > 0) {
            return cacheHashTable[number];
        }

        int result = recursive(hashTable, cacheHashTable, number + 1);

        cacheHashTable[number] = result + 1;

        return cacheHashTable[number];
    }
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> hashTable;
        unordered_map<int,int> cacheHashTable;
        int answer = 0;

        for (auto number : nums) {
            hashTable[number]++;
        }

        for (auto number : nums) {
            int result = recursive(hashTable, cacheHashTable, number);
            answer = max(answer, result);
        }

        return answer;

    }
};