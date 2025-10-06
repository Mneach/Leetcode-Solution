/*

How to solve the problem 

# Using sliding window
1. if k == 0
   - return 0
2. initialize variables
   - left = 0
   - mid = 0
   - right = 0
   - total = 1
   - result = 0
3. while right < nums.size()
   - total *= nums[right]
   - if (total >= k)
     - distanceRight = R - L
     - distanceMid = M - L
     - resultRight = (distanceRight * (distanceRight + 1)) / 2
     - resultMid = (distanceMid * (distanceMid + 1)) / 2
     - result += resultRight - resultMid
     - move mid pointer to right pointer
     - while total >= k && left < right
       - total /= nusm[left]
       - left++
   - increase right pointer by 1
4. return result

Time Complexity : O(N)
N -> size of nums

Memory Complexity : O(1)

*/

class Solution {
private:
    int calculate(int n) {
        return (n * (n + 1)) / 2;
    }
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        if (k == 0) {
            return 0;
        }

        int left = 0;
        int mid = 0;
        int right = 0;
        int result = 0;
        int total = 1;
        
        while (right < nums.size()) {
            total *= nums[right];

            if (total >= k) {
                int distanceRight = right - left;
                int distanceMid = mid - left;
                int resultRight = calculate(distanceRight);
                int resultMid = calculate(distanceMid);
                result += (resultRight - resultMid);
                mid = right;

                while (total >= k && left <= right) {
                    total /= nums[left];
                    left++;
                }
            } 
            right++;
        }

        int distanceRight = right - left;
        int distanceMid = mid - left;
        int resultRight = calculate(distanceRight);
        int resultMid = calculate(distanceMid);
        result += (resultRight - resultMid);

        return result;
    }
};