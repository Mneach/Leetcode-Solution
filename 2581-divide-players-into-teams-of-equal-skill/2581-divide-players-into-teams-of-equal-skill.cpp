/*

How to solve the problem : 

# Using two pointer technique
1. sort skill array in asc
2. initialize two pointer (left = 0 and right = skill.size() - 1)
3. loop while left < right
   - if nums[left] + nums[right] != nums[0] + nums[skill.size() - 1] return -1
   - else 
     - add answer with nums[left] * nums[right]

Time Complexity : O(N log N)
N -> size of skill

Memory Complexity : O(1)

What makes the algorithm run slowly ? 
1. Because we need to sort the skill array and get the sum from minium + maximum number as our referecne

How to improve the solution
1. To get a pair of players, we can use formula : (maximum + minimum) - currentPlayer skill, then find the pair in hashtable
   - example : 
     - minimum = 1, maximum = 5 -> maximum + minimum = 6
     - current player = 4
     - need to find -> 6 - 4 = 2
     - so we just need to find player with skill 2

# Using hash table
1. Construct the hashtable with key = skill and value = how many times that number appear in skill array
2. Get the maximum skill value and minimum skill value
3. Loop for every data in hashtable
   - find the pair using formula above
   - we also need to check if hashTable[current] != hashTable[find], then return -1
   - otherwise multiple current with find and hashTable[current] and put that in answer variable

edge cases : 
1. what if current value == find value
   - ex : current = 5 and find = 5
   - if that the case, we need to check if hashTable[current] % 2 == 0, then add answer variable by (current * current) * hashTable[current] / 2
   - otherwise just return -1

Time Complexity : O(N + M) -> O(N)
N -> size of skills array
M -> size of hashtable

Memory Complexity : O(M)
M -> size of hashtable


*/

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        unordered_map<int,int> hashTable;
        long long answer = 0;
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        
        for (auto data : skill) {
            hashTable[data]++;
            minimum = min(minimum, data);
            maximum = max(maximum, data);
        }

        int sum = maximum + minimum;
        for (auto data : hashTable) {
            int key = data.first;
            int value = data.second;

            int find = sum - key;

            if (find == key) {
                if (value % 2 == 0) {
                    long long result = (1LL * key * key) * (value / 2);
                    answer += result;
                } else {
                    return -1;
                }
            } else {
                if (value == hashTable[find]) {
                    long long result = (1LL * key * find) * value;
                    answer += result;
                } else {
                    return -1;
                }
            }

            hashTable[key] = 0;
            hashTable[find] = 0;
        }

        return answer;
    }
};