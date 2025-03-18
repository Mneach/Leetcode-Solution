class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        
       int answer = 1;
       int currentAnswer = 1; 
       int current = nums[0];
       int last = 1;
       for(int i = 1; i < nums.size(); i++){
           if((nums[i] & current) == 0){
               currentAnswer++;
               current |= nums[i];
           }else{
               answer = max(answer, currentAnswer);
               current = nums[last];
               currentAnswer = 1;
               i = last;
               last = last + 1;
           }
            
       }
        
        answer = max(answer, currentAnswer);
        
        return answer;
    }
};