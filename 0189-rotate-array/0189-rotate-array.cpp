/*


How to solve the problem : 
1. module k by size of nums, since k can be more than array size
2. reverse the current array
   - the reason is because of we need to move the current array to right
3. reverse nums from 0 until k - 1
4. reverse nums from k to nums.size() - 1

Time Complexity : O(N + N)
N -> size of nums

Memory Complexity : O(1)

*/

class Solution {
private:
    void reverse(vector<int>& nums, int left, int right) {
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k %= size;

        reverse(nums, 0, size - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, size - 1);
    }
};