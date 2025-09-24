/*

How to solve the problem 

# Using two pointer technique
1. sort the nums array
2. initialize left and right pointer
3. left = 0 and right = 0
4. find the window where nums[left] + nums[right] <= target
5. loop while left <= right
   - if nums[left] + nums[right] <= right, calculate the result using this formula
     - formula = 2^distance
     - distance = right - left
     - the total combination between nums[left] to nums[right] must be 2^distance, where distance between those numbers

edge cases :
1. what if the distance > 64 ? 
   - we can precompute the answer

Time Complexity : O(N)

Memory Complexity : O(1)

*/

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mod = 1e9 + 7;
        int answer = 0;

        sort(nums.begin(), nums.end());

        // precompute
        vector<int> preCompute(nums.size(), 0);
        preCompute[0] = 1;
        for (int i = 1; i < preCompute.size(); i++) {
            preCompute[i] = (preCompute[i - 1] * 2) % mod;
        }

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                int distance = right - left;
                answer = (answer + (preCompute[distance])) % mod;
                left++;
            } else {
                right--;
            }
        }

        return answer;
    }
};