class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.back() - nums.front();
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (countValidPairs(nums, mid) >= p) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }

private:
    // Helper function to count valid pairs with difference <= threshold
    int countValidPairs(const vector<int>& nums, int threshold) {
        int count = 0;
        
        for (int i = 0; i < nums.size() - 1; ) {
            if (nums[i + 1] - nums[i] <= threshold) {
                count++;
                i += 2;  // Skip the next element as it's part of the current pair
            } else {
                i++;
            }
        }
        
        return count;
    }
};