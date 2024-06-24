class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int answer = 0;        
        int right = INT_MAX;

        int flip = 0;

        for(int i = 0; i < nums.size(); i++){
            
            if(i >= k && nums[i - k] == -1){
                flip--;
            }

            if((nums[i] + flip) % 2 == 0){

                if(i + k > nums.size()) return -1;

                nums[i] = -1;
                answer++;
                flip++;
            }
        }

        return answer;
    }
};