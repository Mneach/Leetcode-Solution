class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int answer = 0;
        unordered_set<int> unique(nums.begin(), nums.end());
        int totalUnique = unique.size();

        unordered_map<int,int> bucket;
        int left = 0;
        int right = 0;
        while (left < nums.size()) {

            while (right < nums.size() && bucket.size() < totalUnique) {
                bucket[nums[right]]++;
                right++;
            }

            if (bucket.size() < totalUnique) break;

            answer += (nums.size() - right) + 1;
            bucket[nums[left]]--; 
            
            if (bucket[nums[left]] == 0) {
                bucket.erase(nums[left]);
            }

            left++;
        }

        return answer;
    }
};