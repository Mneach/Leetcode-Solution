class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int answer = 0; 
       int count = 0;

       for (int i = 0; i < nums.size(); i++) { 
            if (answer != nums[i]) {
                count--;
            } else {
                count++;
            }

            if (count == -1) {
                answer = nums[i];
                count = 1;
            }
       }

       return answer;
    }
};