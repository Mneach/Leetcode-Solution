/*

How to solve the problem : 

# Using Two Pointer Technique
1. Initialize left and right pointer
2. left = 0 and right numbers.size() - 1
3. if nums[left] + nums[right] < target
   - move left pointer to left pointer + 1
   - the reason is because of we need to get the sum more than the current sum and the array is already sorted in increasing order
4. if nums[left] + nums[right] > target
   - move right pointer to right pointer - 1
   - the reason is because of we need to decrease the current su value

Time Complexity : O(N / 2) -> O(N)
N -> size of numbers

Memory Complexity : O(1)

*/


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {

            if (numbers[left] + numbers[right] < target) {
                left++;
            } else if (numbers[left] + numbers[right] > target) {
                right--;
            } else {
                return {left + 1, right + 1};
            }
        }

        return {-1, -1};
    }
};