class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        
        vector<int> maxRightArr(nums.size(), 0);
        
        for(int i = nums.size() - 1; i >= 0; i--){
            if(i == nums.size() - 1){
                maxRightArr[i] = nums[i];
                continue;
            }
            maxRightArr[i] = max(nums[i], maxRightArr[i + 1]);
        }

        int left = 0;
        int answer = 0;
        for(int right = 1; right < nums.size(); right++){

            while(nums[left] > maxRightArr[right] && left <= right){
                left++;
            }

            answer = max(right - left, answer);
        }

        return answer;
    }
};

/*
# Using two pointer approach
1. we need to create max right array
   1.1 start looping from the right to the left, and hold the current max value
2. loop from 0 until nums.size() - 1
   2.1 we need to calculate every process
   2.2 if nums[left] > maxRightArr[current]
   2.3 move left pointer to left + 1
*/