/*

How to solve the problem : 
1. Loop from first index of string s until last index of string s
2. Put the character into the hasthable with key = s[i] and value is pair<first index, last index>
3. Loop for every data in hashtable, we need to do these steps
   - Create unique palindrome template using (key _ key)
   - Looping from first index + 1 until last index -1, those index we can get from hashtable[key]
   - For every index put the current character s[i] into the middle of palindrome index
   - Check if the current palindrome is already exists in cache hash table, we need to skip
   - otherwise we need to put that palindrome into the hashtbale and increase the answer value by 1

Time Complexity : O(N * M)
N -> total english characters that appear in string S
M -> length of String S

Memory Complexity : O(N + M / 3)
N -> total english characters that appear in string s
M -> length os string s
M / 3 -> because we need to create unique palindrome of lenght three

*/

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char,pair<int,int>> bucket;
        unordered_map<string,int> cache;
        int answer = 0;

        for (int i = 0; i < s.length(); i++) {
            if (bucket.count(s[i]) > 0) {
                // update the last index
                bucket[s[i]].second = i;
            } else {
                // put the character along with the index into bucket hash table
                bucket[s[i]] = {i, i};
            }
        }

        for (auto data : bucket) {
            char key = data.first;
            auto index = data.second;
            int firstIndex = index.first;
            int lastIndex = index.second;
            
            string palindrome = "xxx";
            palindrome[0] = key;
            palindrome[2] = key;

            for (int i = firstIndex + 1; i < lastIndex; i++) {
                palindrome[1] = s[i];

                if (cache.count(palindrome) == 0) {
                    answer++;
                    cache[palindrome] = 1;
                }
            }
        }

        return answer;
    }
};