class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int maximum = 0;

        for(auto data : nums) maximum = max(maximum, data);

        vector<int> ump(maximum + 1, 0);

        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                int distance = abs(nums[i] - nums[j]);
                ump[distance]++;
            }
        }

        for(int i = 0; i <= maximum; i++){
            k -= ump[i];

            if(k <= 0) return i;
        }

        return -1;
    }
};