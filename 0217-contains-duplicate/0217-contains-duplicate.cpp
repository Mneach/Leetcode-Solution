class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> answer;

        int length = nums.size();

        for(int i = 0; i < length; i++){
            answer.insert(nums[i]);
        }

        return !(answer.size() == nums.size());
    }
};