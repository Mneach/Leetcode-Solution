/*

How to solve the problem : 
1. Loop from index 1 until index nums.size() - 1
2. for every process we need to check if nums[i] % 2 == nums[i - 1] % 2, then return false

Time Complexity : O(N)

Memory Complexity : O(1)

*/

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] % 2 == nums[i - 1] % 2) {
                return false;
            }
        }

        return true;
    }
};