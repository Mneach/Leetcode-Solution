/*

How to solve the problem : 

# Brute force approach
1. transform all the word in the words array into the 1 or 0
   - if word is start and end with vowel letter we will mark that as 1
   - otherwise we will mark that as 0
   - put those value into the trasnform array
2. for every query, we just need to use the transform array to find the answer, we will start from queries[0] until queries[1] 

Time Complexity : O(N * M)
N -> size of words array
M -> size of queries array

Memory Complexity : O(N)
N -> size of transform array

what make the algorithm run slower ? 
1. because for every query we will loop from left(queries[0]) until right(queries[1]) to get the answer

How to improve the algorithm
1. We will create prefix sum for transform array, so we dont need to loop from left to right to get the answer for every queries

# Prefix Sum Approach
1. Transform all the word in the words array to 1 or 0
   - if the words start and end with vower we will mark that index as 1
   - otherwise we will mark that index as 0
   - we will use this formula to create the prefix sum (prefixSum[i] = prefixSum[i - 1]  + (1 or 0))
2. To get the answer for every queries we can use this formula
   - answer = prefixSum[right] - prefixSum[left - 1]
   - if left == 0, answer = prefixSum[right]

Time Complexity : O(N + M)
N -> size of words array
M -> size of queries array
N + M -> because of we need to create the prefix sum array and find the answer for every queries

Memory Complexity : O(K)
K -> size of prefix sum array
K -> becase we need additional memory to create prefix sum array

*/

class Solution {
public:

    bool isVowel(char x) {
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
            return true;
        }
        
        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefixSum; 
        vector<int> answer;

        for (auto word : words) {
            char first = word[0];
            char last = word[word.length() - 1];
            int result = isVowel(first) && isVowel(last);
            
            if (prefixSum.size() == 0) {
                prefixSum.push_back(result);
            } else {
                prefixSum.push_back(prefixSum[prefixSum.size() - 1] + result);
            }
        }

        for (auto query : queries) {
            int left = query[0];
            int right = query[1];

            if (left == 0) {
                answer.push_back(prefixSum[right]);
            } else {
                answer.push_back(prefixSum[right] - prefixSum[left - 1]);
            }
        }

        return answer;
    }
};