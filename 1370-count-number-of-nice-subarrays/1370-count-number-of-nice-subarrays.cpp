class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int answer = 0;
        int left = 0;
        int tempAnswer = 0;

        int temp = k;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 1) temp--;

            if(temp == 0){
                tempAnswer++;                
            }else if(temp < 0){
                while(left < i && temp < 0){
                    if(nums[left] % 2 == 1) temp++;
                    answer += tempAnswer;
                    left++;
                }
                tempAnswer = 1;
            }
        }

        while(left < nums.size() && temp <= 0){
            if(nums[left] % 2 == 1) temp++;
            answer += tempAnswer;
            left++;
        }

        return answer;
    }
};