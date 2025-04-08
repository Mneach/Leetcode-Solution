class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> ump;

        for (auto num : nums) {
            ump[num]++;
        }

        int markIndex = -1;
        for (int i = 0; i < nums.size(); i += 3) {
            
            for (int j = i; j < i + 3; j++) {
                if (j >= nums.size()) break;
                if (ump[nums[j]] > 1) {
                    markIndex = j;
                    ump[nums[j]]--;
                }
            }
        }

        if (markIndex == -1) return 0;

        return (markIndex / 3) + 1;
    }
};