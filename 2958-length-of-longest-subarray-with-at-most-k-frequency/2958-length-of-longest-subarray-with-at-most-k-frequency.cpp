class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        unordered_map<int,int> ump;
        
        int size = nums.size();
        int answer = 0;
        
        bool flag = false;
        int left = 0;
        for(int right = 0; right < size; right++){
            
            ump[nums[right]]++;
            
            if(ump[nums[right]] > k){
                flag = true;
                answer = max(answer, right - left);
                while(left < right && ump[nums[right]] > k){
                    ump[nums[left]]--;
                    left++;
                }
            }else{
                flag = false;
            }
        }
        
        if(flag == false) answer = max(answer, size - left);
        
        return answer;
    }
};