class Solution {
public:
    
    set<vector<int>> bucket;
    
    void recursive(vector<int> nums, int begin){
        
        if(begin == nums.size()){
            bucket.insert(nums);
        }else{
            for(int i = begin; i < nums.size(); i++){
                swap(nums[begin], nums[i]);
                recursive(nums, begin + 1);
            }
        }
    } 
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> answer;
        
        recursive(nums, 0);
        
        for(auto data : bucket){
            answer.push_back(data);
        }
        
        return answer;
    }
};