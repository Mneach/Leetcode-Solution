#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    unordered_map<int, vector<int>> eds;
    vector<int> nums;

    vector<int> EDS(int i) {
        if (eds.find(i) != eds.end()) return eds[i];

        vector<int> maxSubset;
        for (int k = 0; k < i; ++k) {
            if (nums[i] % nums[k] == 0) {
                vector<int> subset = EDS(k);
                if (maxSubset.size() < subset.size()) maxSubset = subset;
            }
        }
        vector<int> newEntry = maxSubset;
        newEntry.push_back(nums[i]);

        eds[i] = newEntry;
        return newEntry;
    }

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        eds.clear();

        sort(nums.begin(), nums.end());
        this->nums = nums;

        vector<int> maxSubset;
        for (int i = 0; i < n; ++i) {
            vector<int> subset = EDS(i);
            if (maxSubset.size() < subset.size()) maxSubset = subset;
        }

        return maxSubset;
    }
};
