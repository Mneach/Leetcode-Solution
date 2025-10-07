/*

How to solve the problem : 

# Using sliding window + hashtable
1. initialize variables
   - left = 0
   - right = 0
   - result = 0
   - hashTable -> with key = nums[i] and value = how many nums[i] appear in the current sub array
2. while right < nums.size()  
   - add nums[right] into the hashtable
   - while (hashTable[nums[right]] > k)
     - remove the nums[left] from the subarray, equal to decrease hashTable[nums[left]] by 1
     - increase the left pointer by 1
   - get the result using this formula
     - formula : result = max(result, windowSize)
     - windowSize : (right - left) + 1
   - increase the right pointer by 1
3. return the result

Time Complexity : O(N + N) -> O(N)
N -> size of nums

Memory Complexity : O(M)
M -> total different numbers in the hashtable

*/

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> hashTable;
        int left = 0;
        int right = 0;
        int result = 0;

        while (right < nums.size()) {
            hashTable[nums[right]]++;

            while (hashTable[nums[right]] > k) {
                hashTable[nums[left]]--;

                if (hashTable[nums[left]] == 0) {
                    hashTable.erase(nums[left]);
                }

                left++;
            }

            int windowSize = (right - left) + 1;
            result = max(result, windowSize);

            right++;
        }

        return result;
    }
};