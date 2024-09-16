class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int answer = 1;
        int temp = nums[0];
        int tempAnswer = 1;

        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == nums[i + 1] && nums[i] == temp){
                tempAnswer++;
            }else if(nums[i] < nums[i + 1] && temp < nums[i + 1]){
                temp = nums[i + 1];
                answer = 1;
                tempAnswer = 1;
            }else if(nums[i] != nums[i + 1]){
                answer = max(answer, tempAnswer);
                tempAnswer = 1;
            }
        }

        answer = max(answer, tempAnswer);

        return answer;
    }
};