class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> answer; 
        int start = 0;
        int end = nums.size() - 1;
        binary_search(nums, answer, start, end, target);
        
        return answer;
    }
    
    void binary_search(vector<int> nums, vector<int>& answer, int start, int end, int target){
        
        if(start > end) return;
        
        int mid = (start + end) / 2;
        
        if(nums[mid] == target){
           binary_search(nums, answer, start, mid - 1, target);
           answer.push_back(mid);
           binary_search(nums, answer, mid + 1, end, target);
        }else if(nums[mid] > target){
            binary_search(nums, answer, start, mid - 1, target); 
        }else if(nums[mid] < target){
            binary_search(nums, answer, mid + 1, end, target);
        }
        
    }
};