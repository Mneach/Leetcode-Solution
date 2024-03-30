class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k - 1);
    }
    
    int helper(vector<int> &nums, int k){
        
        if(k == 0) return 0;
        
        unordered_map<int,int> ump;
        
        int result = 0;
        int left = 0;
        for(int right = 0; right < nums.size(); right++){
            ump[nums[right]]++;
            
            if(ump.size() > k){
                while(left < right && ump.size() > k){
                    ump[nums[left]]--;
                    
                    if(ump[nums[left]] == 0){
                        ump.erase(nums[left]);
                    }
                    
                    left++;
                }
            }
            
            result += right - left + 1;
        }
        
        cout << result << endl;
        return result;
    }
};