class Solution {
public:
    
    void recursive(vector<int> &nums, vector<vector<int>> &answer, vector<int> bucket, int index){
        if(index == nums.size()){
            answer.push_back(bucket);
        }else{
            bucket.push_back(nums[index]);
            recursive(nums, answer, bucket, index + 1);
            bucket.erase(bucket.begin() + bucket.size() - 1);
            recursive(nums, answer, bucket , index + 1);
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> bucket;
        
        recursive(nums, answer, bucket, 0);
        
        return answer;
    }
};