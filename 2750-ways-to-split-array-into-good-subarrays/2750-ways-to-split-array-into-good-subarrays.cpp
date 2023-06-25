class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        
        if(nums.size() == 1 && nums[0] == 1) return 1;
        
        bool checkOne = false;
        
        vector<unsigned long long> answer;
        unsigned long long current = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1) {
                checkOne = true;
                answer.push_back(current);
                current = 1;
            }else if(checkOne == true){
               current++; 
            }
        }
        
        unsigned long long result = 0;
        
        if(answer.size() > 0){
            result = answer[0];
            
            for(int i = 0; i < answer.size(); i++){
                result = (result * answer[i]) % 1000000007;
            }
        }
        
        return result % 1000000007;
    }
};