/*

How to solve the problem

# Using sliding window
1. create a sub array with size k, start from index 0
2. loop from first index of array until last index of array
   - add the count variable value by arr[index]
   - if index >= k - 1
     - check if count / k >= threshold, then increase answer value by 1
     - decrease the count by arr[index - (k - 1)]
   
Time Complexity : O(N)
N -> size of arr

Memory Compelexity : O(1)

*/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int answer = 0;
        int count = 0;

        for (int i = 0; i < arr.size(); i++) {
            count += arr[i];

            if (i >= k - 1) {

                if (count / k >= threshold) {
                    answer++;
                }

                count -= arr[i - (k - 1)];
            }
        }

        return answer;
    }
};