class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        
        int answer = 0;
        
        int currentAnswer = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            int curr = nums[i + 1] - nums[i];
            
            if(curr == 1){
                int temp = curr;
                while(curr == temp){
                    if(temp == 1) temp = -1;
                    else temp = 1;
                    
                    currentAnswer++;
                    i++;
                    if(i == nums.size() - 1) break;
                    curr = nums[i + 1] - nums[i];
                }
                answer = max(answer, currentAnswer);
                i--;
                currentAnswer = 0;
            }
        }
        
    
        answer = max(answer, currentAnswer);
        
        return answer == 0 ? -1 : answer + 1;
    }
};