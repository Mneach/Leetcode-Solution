/*

How to solve the problem : 
1. loop for every index in string t and do these processes
   1.1 check if character at index i in string t is already exist in hash table
   1.1.1 if the character is not exist, we will put that character into the hash table with key = t[index] and value = s[index]
   1.1.2 if the character exist, we need to check if the value of hashtable[t[index]] == s[index], if the value is not equal that means we cannot replact the character in string s at index i with the caracter in string t at index i, we can simply return false. Otherwise repeat again from 1.1

Note : 
1. Order is matter
2. length of string s and t are equal

Time Complexity : O(N)
N -> length of string T

Memory Complexity : O(N)
N -> length of string T

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
                if (visited[s[i]] == true) return false;
                hashTable[t[i]] = s[i];
                visited[s[i]] = true;
            }
        }

        return true;
    }
};