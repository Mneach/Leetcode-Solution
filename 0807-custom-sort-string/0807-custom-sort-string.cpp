/*

How to solve the problem : 

# Hashtable Approach
1. create hashtable for string s
   - key = character
   - value = total character
2. loop for every character in the order string
   - for every process we need to check if order[i] is exist in hashtable
   - if it is exists append the order[i] as much as total character in hashtable to answer string
   - otherwise we can skip the append process
3. because there is a case when order string not fully cover all the characters in string s
   - loop for every character in string s
   - if value of hashtable[s[i]] != 0, we need to append that character to answer string
   - otherwise just skip the append process

Time Complexity : O(N + M) = O(N)
N -> length of order string
M -> length of s string

Memory Complexity : O(N)
N -> length of order string

*/

class Solution {
public:
    string customSortString(string order, string s) {
        string answer = "";
        unordered_map<char, int> bucket;        

        for (auto character : s) {
           bucket[character]++; 
        }

        for (int i = 0; i < order.size(); i++) {
            char key = order[i];
            int value = bucket[key];

            if (value > 0) {
                for (int j = 0; j < value; j++) {
                    answer += key;
                }
                
                bucket[key] = 0;
            }
        }

        for (int i = 0; i < s.length(); i++) {
            int key = s[i];
            int value = bucket[key];

            if (value > 0) {
                for (int j = 0; j < value; j++) {
                    answer += key;
                }
                bucket[key] = 0;
            }
        }

        return answer;
    }
};