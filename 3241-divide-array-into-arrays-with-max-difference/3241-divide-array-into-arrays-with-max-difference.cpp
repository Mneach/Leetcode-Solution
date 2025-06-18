class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> answer;
        for(int i = 0; i < nums.size() - 2; i++){
           if(nums[i + 2] - nums[i] <= k){
           answer.push_back({nums[i], nums[i + 1] , nums[i + 2]});
            i += 2;
        }
      }
        
        if(answer.size() == nums.size() / 3){
        return answer;
}
        
        vector<vector<int>> temp;
        return temp;
    }
};