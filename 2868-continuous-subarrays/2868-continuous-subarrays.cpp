class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {

        long long answer = 0;
        map<int,int> bucket;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {

            bucket[nums[right]]++;

            while (bucket.rbegin() -> first - bucket.begin() -> first > 2) {
                bucket[nums[left]]--;

                if (bucket[nums[left]] == 0) {
                    bucket.erase(nums[left]);
                }

                left++;
            }

            answer += (right - left) + 1;
        }
        
        return answer;
    }
};