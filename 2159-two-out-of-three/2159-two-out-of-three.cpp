class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> answer;
        vector<vector<bool>> bucket(3, vector<bool>(101, 0));

        for (auto num : nums1) bucket[0][num] = true;
        for (auto num : nums2) bucket[1][num] = true;
        for (auto num : nums3) bucket[2][num] = true;


        for (int i = 0; i < 101; i++) {
            if (bucket[0][i] + bucket[1][i] + bucket[2][i] > 1) {
                answer.push_back(i);
            }
        }

        return answer;
    }
};