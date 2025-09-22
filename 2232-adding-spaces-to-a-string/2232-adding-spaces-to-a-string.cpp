/*

How to solve the problem : 

# Using Brute Force Solution
1. For every single character in string s, we need to check if the current index exist in the spaces array, if it is exist, than append the current result with space and s[i]

Time Complexity : O(N * M)
N -> size of the string
M -> size of the spaces

# What makes the algorithm run slowly ? 
1. Because for every index in string s, we need to check if the curret index appear in the spaces array

# How to improve ? 
1. what if we are using two pointer to maintain the index of string s and the index of array spaces, so we don't need to loop from the first index until the last index in spaces array

# Using two pointer technique
1. Define left and right pointer with value 0
2. Left pointer for string s and right pointer for spaces array
3. loop from the first index of string s until last index of string s
   - if (right < spaces.size() && left == spaces[right]), then append answer with space + s[left] and increase right pointer by 1
   - otherwise just append answer with s[left]
   - increase left pointer by 1

Time Complexity : O(N + M)
N -> size of string s
M -> size of the spaces

Memory Complexity : O(1)

*/

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int left = 0;        
        int right = 0;
        string answer = "";

        while (left < s.length()) {

            if (right < spaces.size() && left == spaces[right]) {
                answer += ' ';
                answer += s[left];
                right++;
            } else {
                answer += s[left];
            }

            left++;
        }

        return answer;
    }
};