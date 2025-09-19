/*

How to solve the problem : 

# Using Hashtable and sliding window

1. Loop from the first index until the last index of string
2. Create the sub string with length 10, start with index 0
3. if the length of the current sub string == 10, then we need to do these steps
   - put the sub string into the hashtable with key = substring value, how many times that substring appear in string s
   - remove the first character of the current substring
4. Loop for every data in hashtable, then we need to check if the value of the current data is more than 1, that means the DNA sequance appear more than 1 time

Time Complexity : O(N * M) -> O(N * 10) -> O(N)
N -> size of string s
M -> total process to delete first character -> worst case (10 process)

Memory Complexity : O(K + P)
K -> size of hashtable
P -> size of answer array


*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> answer;
        unordered_map<string,int> hashTable;

        string subString = "";
        for (int i = 0; i < s.length(); i++) {
            subString += s[i];

            if (subString.length() == 10) {
                hashTable[subString]++;

                // remove the first character
                // first parameter = start index
                // second parameter = length of string that we want to delete
                subString.erase(0, 1);
            }
        }

        for (auto data : hashTable) {
            string key = data.first;
            int value = data.second;

            if (value > 1) {
                answer.push_back(key);
            }
        }

        return answer;
    }
};