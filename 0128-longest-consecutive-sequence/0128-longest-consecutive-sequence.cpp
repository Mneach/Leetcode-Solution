/*

How to solve the problem : 

# Using hash table
1. loop for every number in nums array
2. to get the current answer at number x we can use this formula
   - formula : result from prev number + result from after the current number + current number value
   - formula : hashTable[number - 1] + hashTable[number + 1] + 1
3. update the value of most left number in the current sequance (key = current number - hashTable[number - 1])
4. update the value of most right number in the current sequance (key = current number + hashTable[number + 1]);
5. calculate the answer with this fomula (answer = max(answer, hashTable[number]))

Note : 
1. What is the reason update the prev and next number in hash table ? 
A : the reason is because of we dont know the order of the number and we dont want to sort the data here, thats why we need to update the most left and most right number in the current sequance

Time Complexity : O(N)
N -> size of nums array

Memory Complexity : O(N)
N -> size of hash table

*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> hashTable;
        int answer = 0;

        for (auto number : nums) {

            if (hashTable[number] == 0) {
                hashTable[number] = hashTable[number - 1] + hashTable[number + 1] + 1; 

                // update most left number
                hashTable[number - hashTable[number - 1]] = hashTable[number];

                // update most right number
                hashTable[number + hashTable[number + 1]] = hashTable[number];

                answer = max(answer, hashTable[number]);
            }

            // we can simply skip the result that already calculated
        }

        return answer;
    }
};