class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        int maxNumber = 0;
        
        for(auto data : nums){
            maxNumber = max(data, maxNumber);
        }
        
        long long answer = 0;
        int left = 0;
        for(int right = 0; right < nums.size(); right++){
            
            if(nums[right] == maxNumber){
                k--;
            }
            
            while(k == 0){
                if(nums[left] == maxNumber){
                    k++;
                }
                left++;
            }
            
            answer += left;
        }
        
        return answer;
    }
};