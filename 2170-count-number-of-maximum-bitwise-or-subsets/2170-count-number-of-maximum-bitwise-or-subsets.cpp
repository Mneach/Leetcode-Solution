class Solution {
public:

    void recursive(vector<int>& nums, map<int,int,greater<int>> &mp, int current, int result){
        if(current >= nums.size()){
            return;
        }

        mp[result]++;
        for(int i = current + 1; i < nums.size(); i++){
            recursive(nums, mp, i, result | nums[i]);    
        }
    }

    int countMaxOrSubsets(vector<int>& nums) {
        map<int, int, greater<int>> mp; 

        for(int i = 0; i < nums.size(); i++){
            recursive(nums, mp, i, nums[i]);
        }

        return mp.begin() -> second;
    }
};