/*

How to solve the problem : 
1. Iterate over every index i in string t (or s, since both have equal length).
2. Check the mapping in a hash table (dictionary): 
   2.1 Case 1: Character t[i] is not in the hash table
   2.1.1 If s[i] has not been visited yet, create a mapping t[i] → s[i] in the hash table and mark s[i] as visited.
   2.1.2 If s[i] has already been visited by another character, return false (because two characters from t would map to the same character in s).
   
   2.2 Case 2: Character t[i] already exists in the hash table
   2.2.1 Verify if the stored mapping hashTable[t[i]] == s[i].
   2.2.2 If not equal, return false (because it would break the consistency rule).

3. If the loop completes without conflicts, return true.

Note : 
1. Order is matter
2. length of string s and t are equal

Time Complexity : O(N)
N -> length of string T

Memory Complexity : O(N + M)
N -> length of string T
M -> length of string S

*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<int,int> hashTable;         
        unordered_map<int,bool> visited;

        for (int i = 0; i < t.length(); i++) {

            if (hashTable.count(t[i]) > 0) {

                if (hashTable[t[i]] != s[i]) {
                    return false;
                } 

            } else {
                if (visited[s[i]] == true) {
                    return false;
                }
                hashTable[t[i]] = s[i];
                visited[s[i]] = true;
            }
        }

        return true;
    }
};