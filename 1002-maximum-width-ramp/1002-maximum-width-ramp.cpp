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

# Intuition
- you need to know the maximum number that you can reach with the current number
- calculate the distance between those numbers
- to know what is the maximum number that we can reach, we can store that maximum number in an array or stacks
- alwasy start from right to left, to its will be take o(N) to construct the maximum number that we can reach with the current number

# Using two pointer approach
1. we need to create max right array
   1.1 start looping from the right to the left, and hold the current max value
2. loop from 0 until nums.size() - 1
   2.1 we need to calculate every process
   2.2 if nums[left] > maxRightArr[current]
   2.3 move left pointer to left + 1

Time Complexity : O(N)
O(N) -> we need to loop from left to right to construct the answer

Memory Complexity : O(N)
O(N) -> we need to use an array or stack to store the maximum number in the current state
*/