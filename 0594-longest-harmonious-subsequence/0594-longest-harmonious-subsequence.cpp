class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> bucket;
        int answer = 0;

        for (auto num : nums) {
            bucket[num]++;

            if (bucket[num + 1] > 0) {
                answer = max(answer, bucket[num] + bucket[num + 1]);
            }

            if (bucket[num - 1] > 0) {
                answer = max(answer, bucket[num] + bucket[num - 1]);
            }
        }

        return answer;
    }
};