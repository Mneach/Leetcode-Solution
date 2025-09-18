/*

How to solve the problem : 
1. Construct hashtable with key = lower english letter, and value = total character that appear in hash table
2. Loop from first index of P until last index of P
   - Put the character into the hashtable hashTable[p[i]]++
3. Loop from first index of s until last index of s
   - Create the sub array with size P
   - put the left pointer in the most left index of sub array
   - put the right pointer in the most right index of sub array
   - Remove current character from hashtable -> hashtable[s[right]]--
   - if the current sub array length == P, then loop for every character in hashtable and check if all the value in hashtable data == 0, then mark current left value as an answer
     - Remove most right character to the hashtable -> hashtable[s[left]]--
     - Add most left character to the hasthable -> hashtable[s[right]]++
     - Move left pointer to left pointer + 1
   - Move right pointer to right pointer + 1

Time Complexity : O((N - M) * K)
N -> size of string s
M -> size of string p
K -> size of hashtable -> max(26)

Memory Complexity : O(K + N)
K -> size of hashtable -> max(26)
N -> size of string s

*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> hashTable;        
        vector<int> answer;
        int left = 0;
        int right = 0;

        for (auto c : p) {
            hashTable[c]++;
        }

        while(right < s.length()) {
            
            hashTable[s[right]]--;

            if ((right - left) + 1 >= p.length()) {
                bool valid = true;

                for (auto data : hashTable) {
                    char key = data.first;
                    int value = data.second;

                    if (value != 0) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    answer.push_back(left);
                }

                hashTable[s[left]]++;
                left++;
            }

            right++;
        } 

        return answer;
    }
};