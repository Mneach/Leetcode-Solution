class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        vector<int> answer;
        
        for(int i = 0; i < n; i++){
            int index = i;
            
            while(index < nums.size()){
                answer.push_back(nums[index]);
                index += n;
            }
        }
        
        return answer;
    }
};