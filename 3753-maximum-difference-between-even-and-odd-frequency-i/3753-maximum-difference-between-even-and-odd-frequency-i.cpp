/*

How to solve the problem : 

# Using hashtable
1. Put all the charcter in string s into the hashtable with key = character, value = total character x appear in string s
2. loop from hash table to get the highest and lowest value for odd and even freq data
3. get the maximum value from those data

Time Complexity : O(N + (M + M))
N -> length of string S
M -> total different character that appear in string s

Memory Complexity : O(M)
M -> total differenet character that appear in string s

*/

class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> bucket;

        for (auto c : s) {
            bucket[c]++;
        }
        
        int odd = 0;
        int even = INT_MAX;
        
        for (auto data : bucket) {
            int freq = data.second;

            if (freq % 2 == 1) {
                odd = max(odd, freq);
            } else {
                even = min(even, freq);
            }
        }
        
        return odd - even;
    }
};