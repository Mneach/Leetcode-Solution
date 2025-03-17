class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> ump;

        for (auto num : nums) ump[num]++;

        for (auto data : ump) {
            if (data.second % 2 == 1) return false;
        }

        return true;
    }
};