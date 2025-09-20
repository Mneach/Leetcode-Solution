/*

How to solve the problem 
1. Find decreasing value in array nums
2. start from that index until current decreasing value index - 1
3. if there is another decreasing value return false

Time Complexity : O(N + N)
N -> size of nums
N + N -> since we need to loop 2 times for every number in nums array

Memory Complexity : O(1)

*/

class Solution {
public:
    bool check(vector<int>& nums) {
        
        // find decreasing value
        int index = -1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            return true;
        }

        int start = (index + 1) % nums.size();

        while (start != index) {
            if (start == 0 && nums[start] < nums[nums.size() - 1]) {
                return false;
            } else if (start > 0 && nums[start] < nums[start - 1]) {
                return false;
            }
            start = (start + 1) % nums.size();
        }

        return true;
    }
};