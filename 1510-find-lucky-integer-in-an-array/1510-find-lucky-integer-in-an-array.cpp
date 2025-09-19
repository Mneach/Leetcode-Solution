/*

1. Put all of those numbers in the hashtable with key = number and value = how many times that number appears in nums of array
2. Loop for every data in hashtable, and get the largest lucky integer

Time Complexity : O(N + M)
N -> size of array
M -> size of hashtable

Memory Complexity : O(M)
M -> size of hashtable

*/

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> hashTable;
        int answer = -1;

        for (auto number : arr) {
            hashTable[number]++;
        }

        for (auto data : hashTable) {
            int key = data.first;
            int value = data.second;

            if (key == value) {
                answer = max(answer, key);
            }
        }

        return answer;
    }
};