class Solution {
public:
    
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        
        int answer = 0;
        int current = 1;
        
        for(int left = 0, right = 0; right < nums.size(); right++){
            current *= nums[right];
            
            while(current >= k){
                current /= nums[left++];
            }
            
            answer += right - left + 1;
        }
        
        return answer;
    }
    
};