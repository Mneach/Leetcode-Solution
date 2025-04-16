class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long answer = 0;
        unordered_map<int, long long> ump;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            int number = nums[right];
            k -= ump[number]++;

            while (k <= 0) {
                k += --ump[nums[left++]];
            }

            answer += left;
        }

        return answer;
    }
};