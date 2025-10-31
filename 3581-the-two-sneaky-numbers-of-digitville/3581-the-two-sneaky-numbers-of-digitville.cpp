class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> bucket(101, 0);
        vector<int> results;
        for (int i = 0; i < nums.size(); i++) {
            bucket[nums[i]]++;
        }

        for (int i = 0; i < bucket.size(); i++) {
            if (bucket[i] == 2) {
                results.push_back(i);
            }
        }

        return results;
    }
};