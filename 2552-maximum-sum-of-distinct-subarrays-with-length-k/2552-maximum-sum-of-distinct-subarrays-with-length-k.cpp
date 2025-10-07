/*

How to solve the problem

# Using sliding window + hashtable
1. initalize variables
   - left = 0
   - right = 0
   - sum = 0
   - result = 0
   - hashtable -> with key = nums[i] and value = how many times nums[i] appear in the current sub array
2. while right < nums.size()
   - add sum by nums[right] 
   - add nums[right] into the hashtable
   - windowSize = (right - left) + 1
   - while hashTable[nums[right]] > 1 || windowSize > k
     - remove nums[left] from hashtable
     - decrease sum by nums[left]
     - increaes left pointer by 1
     - redefine the window size (windowSize = (right - left) + 1)
   - if (windowSize == k)
     - get the maximum result using this formula
     - formula : result = max(result, sum)
   - increaes right pointer by 1
3. return the result

Time Complexity : O(N + N) -> O(N)
N -> size of nums

Memory Complexity : O(K)

*/


class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hashTable;
        int left = 0;
        int right = 0;
        long long result = 0;
        long long sum = 0;

        while (right < nums.size()) {
            sum += nums[right];
            hashTable[nums[right]] += 1;

            int windowSize = (right - left) + 1;

            while (hashTable[nums[right]] > 1 || windowSize > k) {
                hashTable[nums[left]]--;
                sum -= nums[left];
                left++;
                windowSize = (right - left) + 1;
            }

            windowSize = (right - left) + 1;
            if (windowSize == k) {
                result = max(result, sum);
            }

            right++;
        }

        return result;
    }
};