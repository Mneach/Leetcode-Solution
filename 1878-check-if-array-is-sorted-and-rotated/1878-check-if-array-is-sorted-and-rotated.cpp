class Solution {
public:
    bool check(vector<int>& nums) {
        if (nums.size() == 2) return true;

        int totalNotValid = 0;
        for (int i = 0; i < nums.size(); i++) {
            int prev = i == 0 ? nums.size() - 1 : i - 1;
            int current = i;
            int next = i == nums.size() - 1 ? 0 : i + 1;
            
            if (nums[current] >= nums[prev] && nums[next] >= nums[current]) continue;
            totalNotValid++;
        }

        if (totalNotValid > 2) return false;
        else return true;
    }
};