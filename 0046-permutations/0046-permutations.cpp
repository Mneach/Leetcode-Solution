class Solution {
public:
    
    void recursive(vector<vector<int>>& answer, vector<int> nums, int begin){
        
        if(begin == nums.size()){
            answer.push_back(nums);
        } else{
            for(int i = begin; i < nums.size(); i++){
                swap(nums[begin], nums[i]);
                recursive(answer, nums, begin + 1);
            }    
        }
        
        
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        
        recursive(answer, nums, 0);
        
        return answer;
    }
};