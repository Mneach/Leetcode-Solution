class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // key : number
        // value : index
        unordered_map<int,int> bucket;
        int answer = 0;

        int left = 0;
        int temp = 0;
        for (int right = 0; right < nums.size(); right++) {

            if (bucket.count(nums[right]) > 0 && bucket[nums[right]] >= left) {
                while (left < right) {
                    temp += nums[left];
                    left++;
                }
                answer = max(answer, temp);
                left = bucket[nums[right]] + 1;
                temp = 0;
            }
            
            bucket[nums[right]] = right;
        }

        temp = 0;
        while (left < nums.size()) {
            temp += nums[left]; 
            left++;
        }

        return max(answer, temp);
    }
};