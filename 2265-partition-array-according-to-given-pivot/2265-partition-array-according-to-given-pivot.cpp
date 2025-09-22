/*

How to solve the problem : 

# Brute Force Solution Approach
1. Create another array, lets call it answer array
2. loop from first index of nums until last index of nums, put all the number < pivot to the answer array
3. loop from first index of nums until last index of nums, put all the number == pivot to the answer array
4. loop from first index of nums until last index of nums, put all the number > pivot to the answer array
5. return the answer array

Time Complexity : O(N + N + N) = O(N)
N -> size of nums
first N -> to get all of the number in nums array that have value < pivot
second N -> to get all of the numbers in nums array that have value == pivot
third N -> to get all of the number in nums array that have value > pivot

Memory Complxity : O(M)
M -> size of answer array

*/

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> answer(nums.size(), 0);
        int less = 0;
        int more = nums.size() - 1;

        for (int i = 0, j = nums.size() - 1; i < nums.size(); i++, j--){
            if (nums[i] < pivot) {
                answer[less] = nums[i];
                less++;
            }

            if (nums[j] > pivot) {
                answer[more] = nums[j];
                more--;
            }
        }

        while (less <= more) {
            answer[less] = pivot;
            less++;
        }

        return answer;
    }
};