class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        
        int answer = 0;
        
        for(int i = 0; i < nums.size(); i++){
            int temp = 0;
            
            if(nums[i] % 2 == 0 && nums[i] <= threshold){
                int current = 0;
                while(i < nums.size()){
                    if(nums[i] % 2 == current && nums[i] <= threshold){
                        temp++;
                    }else{
                        break;
                    }
                    
                    current++;
                    current %= 2;
                    i++;
                }
                i--;
            }   
            
            answer = max(temp, answer);
        }
        
        return answer;
    }
};