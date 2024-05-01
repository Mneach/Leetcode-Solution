class Solution {
public:
    int minimumSplits(vector<int>& nums) {

        int answer = 1;
        int temp = -1;
        for(int i = 0; i < nums.size(); i++){
            if(temp == -1){
                temp = nums[i];
            }else{
                if(gcd(temp, nums[i]) == 1){
                    temp = nums[i];
                    answer++;
                }else{
                    temp = gcd(temp, nums[i]);
                }
            }
        }
        
        return answer;
    }
};