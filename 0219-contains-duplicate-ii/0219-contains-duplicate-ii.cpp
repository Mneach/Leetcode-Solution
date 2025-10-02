/*

How to solve the problem

# Using sliding window
1. loop from first index of nums until last index of nums
2. if nums[i] already exists in the hashtable
   - return true
3. otherwise
   - put nums[i] in the hashtable
4. if (i >= k)
   - erase hashtable with key = nums[i - k]

Time Complexity : O(N)
N -> size of nums

Memory Complexity : O(K)

*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> hashTable;

        for (int i = 0; i < nums.size(); i++) {
            int number = nums[i];

            if (hashTable[number] > 0) {
                return true;
            }

            hashTable[number]++;

            if (i >= k) {
                hashTable.erase(nums[i - k]);
            }
        }        

        return false;
    }
};