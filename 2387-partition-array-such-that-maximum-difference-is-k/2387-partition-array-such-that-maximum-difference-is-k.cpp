#include <vector>
#include <algorithm>

class Solution {
public:
    int partitionArray(std::vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        
        std::sort(nums.begin(), nums.end());
        
        int partitions = 1;
        int current_min = nums[0];
        
        for (const int num : nums) {
            if (num - current_min > k) {
                partitions++;
                current_min = num;
            }
        }
        
        return partitions;
    }
};