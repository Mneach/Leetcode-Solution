/*

How to solve the problem

# Using two pointer
1. find the number that closest to the x, lets called it index
2. put left pointer = index - 1 and right pointer = index + 1
3. just need to check
   - if arr[right] - arr[index] < arr[left] - arr[index], then pick arr[right] and increase right pointer
   - else pick arr[left] and increase left pointer
   - do those steps until right - left + 1 == k
4. loop from left to right
   - put all of those numbers into the answer variable

Time Compelxity : O(N + K)
N -> size of arr

Memory Complexity : O(1)

# What makes the algorithm run slowly ? 
1. because we need to find the number that closest to the x

# How to improve the solution ? 
1. we can change from linear search to binary search

# Using two pointer + binary search
1. find the number that closest to the x using binary search
2. put left pointer = index - 1 and right pointer = index + 1
3. just need to check
   - if arr[right] - arr[index] < arr[left] - arr[index], then pick arr[right] and increase right pointer
   - else pick arr[left] and increase left pointer
   - do those steps until right - left + 1 == k
4. loop from left to right
   - put all of those numbers into the answer variable

Time Compelxity : O(log N + K)
N -> size of arr

Memory Complexity : O(1)


*/


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> results;
        int size = arr.size();
        int left = 0;
        int right = size - 1;

        while (left < right) {
            int mid = (right + left) / 2;

            if (arr[mid] < x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        left = left - 1;
        right = left + 1;

        while (right - left - 1 < k) {
            if (left < 0) {
                right++;
            } else if (right >= arr.size()) {
                left--;
            } else if (abs(arr[left] - x) <= abs(arr[right] - x)) {
                left--;
            } else {
                right++;
            }
        }

        left++;
        while (left < right) {
            results.push_back(arr[left]);
            left++;
        }

        return results;
    }
};