class Solution {
public:
    
    void recursive(vector<int> candidates, int target, int currentSum, int index, vector<int> temp, vector<vector<int>> &answers){
        if(currentSum > target) return;
        
        if(currentSum == target){
            answers.push_back(temp);
        }
        
        for(int i = index; i < candidates.size(); i++){
            temp.push_back(candidates[i]);
            recursive(candidates, target, currentSum + candidates[i], i, temp, answers);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answers;
        vector<int> temp;
        
        recursive(candidates, target, 0, 0, temp, answers);
        
        return answers;
    }
};