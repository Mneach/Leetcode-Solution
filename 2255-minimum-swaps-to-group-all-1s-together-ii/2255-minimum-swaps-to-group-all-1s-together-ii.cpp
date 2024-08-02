class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int answer = INT_MAX;

        int totalOne = 0;

        for(auto data : nums) if(data == 1) totalOne++;

        int left = 0;
        int right = 0;
        int one = 0;
        int zero = 0;

        while(left < nums.size()){
            if(right < totalOne){

                if(nums[right] == 0) zero++;

                right++;
            }else{
                answer = min(answer, zero);
                if(nums[left] == 0) {
                    zero--;
                }

                if(nums[right % nums.size()] == 0) {
                    zero++;
                }

                left++;
                right++;
            }
        }

        answer = min(answer, zero);

        return answer;
    }
};