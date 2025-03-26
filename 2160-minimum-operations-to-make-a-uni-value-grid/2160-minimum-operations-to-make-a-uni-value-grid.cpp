class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int rows = grid.size(), cols = grid[0].size();
        
        // Flatten the grid and check if all elements have the same remainder mod x
        for (const auto& row : grid) {
            for (int num : row) {
                if (num % x != grid[0][0] % x) return -1;
                nums.push_back(num);
            }
        }
        
        // Sort the array to determine median easily
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];
        
        // Calculate the total operations needed to make all elements equal to median
        int operations = 0;
        for (int num : nums) {
            operations += abs(num - median) / x;
        }
        
        return operations;
    }
};
