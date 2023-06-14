class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int answer = 0;
        int current = 0;
        int prev = 0;
        bool hasDeleteOneElement = false;
        int currentIndex = 0;
        while(currentIndex < nums.size()){
            if(nums[currentIndex] == 1) {
                current++;
            } else {
                answer = max(answer, current + prev);
                prev = current;
                current = 0;
                hasDeleteOneElement = true;
            }
            currentIndex++;
        }
        
        answer = max(answer, current + prev);
        if(!hasDeleteOneElement) answer -= 1;
        
        return answer;
    }
};