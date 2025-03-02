class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int,int> ump;

        for (auto data : nums1) {
            int id = data[0];
            int value = data[1];

            ump[id] += value;
        }

        for (auto data : nums2) {
            int id = data[0];
            int value = data[1];

            ump[id] += value;
        }

        vector<vector<int>> answer;
        for (auto data : ump) {
            answer.push_back({data.first, data.second});
        }

        sort(answer.begin(),answer.end());

        return answer;
    }
};