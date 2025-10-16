
/*

How to solve the problem

# Main Idea
1. Try all possibility of capacity value. so we will start from 0 until maximum nums in array
   - the definition of capacity value is the maximum amount of money he steals from one house of all the houses he robbed
2. if the current capacity value satisfy the condition based on what has been written in the problem description, current capacity might be the answer
   - current capacity will be mark as a valid answer, if the total house that we can rob more than or equal to K
3. alwasy find the minimum capacity that satisfy the condition

# Using brute force solution
1. initialize variables
   - maximumCapacity
   - result
2. get the maximum capacity from nums array
3. loop from 0 until maximum capacity 
   - count = 0
   - loop for every number in nums array
     - if nums[i] <= current capacity
       - i += 2, the reason is because of we cannot steal a money from adjacent houses
       - count++
     - else 
       - i += 1
   - if (count >= k)
     - result = min(result, current capacity)
4. return the result

Time complexity : O(M + N * M)
N -> maximum capacity in nums array
M -> size of nums

M -> to get the maximum capacity
N * M -> to get the minimum capacity

Memory Complexity : O (1)

# Can we improve the solution 
1. Yes we can, instead of using linear search to find a valid capacity, it is better to use binary search to find a valid capacity, so the time complxity can be reduce from (N * M) to (M log N)

# Using binary search
1. initialize variables
   - maximumCapacity
   - result
2. get the maximum capacity from nums array
3. do binary search algorithrm to find a valid capacity
   - left = 0
   - right = maximumCapacity
   - while <= right
     - mid = left + (right - left) / 2
     - currentCapcity = mid
     - check if the current capacity is valid
       - result = min(result, mid)
       - right = mid - 1
     - else
       - left = mid + 1
4. return the result

Time Complxity : O (N * M)
N -> maximum capacity in nums array
M -> size of nums array

Memory Complexity : O (1)

*/

class Solution {
private:
    bool isValidCapacity(vector<int> &nums, int k, int currentCapacity) {
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= currentCapacity) {
                i++;
                count++;
            }
        }

        return count >= k;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int maximumCapacity = *max_element(nums.begin(), nums.end());
        int result = 0;

        int left = 0;
        int right = maximumCapacity;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int currentCapacity = mid;

            if (isValidCapacity(nums, k, currentCapacity)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};