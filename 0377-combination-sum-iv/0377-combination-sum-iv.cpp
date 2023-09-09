class Solution {
public:
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> answer(target + 1, 0);
        
        answer[0] = 1;
        
        for(int i = 1; i <= target; i++){
            for(auto data : nums){
                if(i >= data){
                    answer[i] += answer[i - data];
                }
            }
        }
        
        return answer[target];
    }
};