class Solution {
public:
    
    void dfs(vector<int>& nums, int currentIndex, int &answer, int currentXor){
        if(currentIndex == nums.size()) return;
        
        answer += currentXor;
        
        for(int i = currentIndex + 1; i < nums.size(); i++){
            dfs(nums, i, answer, currentXor ^ nums[i]);
        }
    }
    
    int subsetXORSum(vector<int>& nums) {
        
        int answer = 0;
        for(int i = 0; i < nums.size(); i++){
            dfs(nums, i, answer, nums[i]);
        }
        
        return answer;
    }
};