class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> bucket;

        int answer = 0;
        int left = 0;
        int temp = 0;
        for (int right = 0; right < nums.size(); right++) {
            
            if (bucket.count(nums[right]) > 0 && bucket[nums[right]] >= left) {
                answer = max(temp, answer);
                int stopPoint = bucket[nums[right]];
                while (left < stopPoint + 1) {
                    temp -= nums[left];
                    left++;
                }
            }

            bucket[nums[right]] = right;
            temp += nums[right];
        }

        return max(answer, temp);
    }
};