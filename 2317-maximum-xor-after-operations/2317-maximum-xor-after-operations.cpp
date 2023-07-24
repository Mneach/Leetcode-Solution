class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        
        int answer = 0;
        for(int i = 0; i < nums.size(); i++){ 
            answer = answer | nums[i];
        }
        
        return answer;
    }
};