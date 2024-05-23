class Solution {
public:
    
    void backtrack(vector<int>& nums, unordered_map<int,int> &ump, int k, int currentIndex, int &answer){
        
        if(currentIndex >= nums.size()){
            answer++;
            return;
        }
        
        // if satify the condition, continue to insert the number to the subset
        // a - b = k -> a = k - b or - b = k - a
        if(ump[nums[currentIndex] - k] == 0 && ump[nums[currentIndex] + k] == 0){
            ump[nums[currentIndex]]++;
            backtrack(nums, ump, k, currentIndex + 1, answer);
            
            // remove from the subset
            ump[nums[currentIndex]]--;
        }
        
        // continue without taking the number
        backtrack(nums, ump, k, currentIndex + 1, answer);
      
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        int answer = 0;
        unordered_map<int,int> ump;
        
        backtrack(nums, ump, k , 0, answer);
        
        return answer - 1;
    }
};