/*

How to solve : 

# Bruteforce solution
1. createt left part and right part
2. left part start from 0 until right index
3. right part alwasy start from left index + 1
4. every process, put the result into the answer variable

Time complexity : (N ^ 2)
N -> size of nums array

# Two pointer solution
1. create left part and right part
2. left part should be start from 0
3. for right part , we need to sum the right part start from index 1 until nums.size() - 1
4. every process we need to do this
   4.1 compare left part and right part
   4.2 if comparison result is fullfill the condition based on the problem desc, increment the answer
   4.3 move left pointer to left pointer + 1
   4.4 add left part with nums[left]
   4.5 minus right part with nums[right]
   4.6 move right pointer to the right pointer + 1

Time Complexity : O(N)
N -> size of array nums

Memory Complexity : O(1)

*/

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {

        int answer = 0;
        long long totalLeft = nums[0];
        long long totalRight = 0;

        for (int i = 1; i < nums.size() ; i++) {
            totalRight += nums[i];
        }

        for (int right = 1; right < nums.size(); right++) {
            if (totalLeft >= totalRight) {
                answer++;
            }
            totalLeft += nums[right];
            totalRight -= nums[right];
        }

        return answer;
    }
};