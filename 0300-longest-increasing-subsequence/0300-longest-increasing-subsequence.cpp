class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> bucket(nums.size(), 1);
        
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    bucket[i] = max(bucket[j] + 1, bucket[i]);
                }
            }
        }
        
        int answer = 1;
        for(auto data : bucket){
            answer = max(data, answer);
        }
        
        return answer;
    }
};