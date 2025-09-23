/*

How to solve the problem 
1. initialize three pointer
2. i = 0, j = i + 1, k = j + 1
3. loop from first index of nums until last index of nums
4. if nums[i] + nums[j] + nums[k] = 0, put those number in set<vector<int>>

Time Complexity : O(N * N * N * logN) -> (N^3 * log N)

Memory Complexity : O(M)
M -> size of the set data structure

What makes the algorithm run slowly ? 
1. Is because of we need to create all the combinations of the number in nums

How we can improve the algorithm ? 
1. what if we change the formula
   - from nums[i] + nums[j] + nums[k] = 0 -> nums[i] + nums[j] = -nums[k]
2. so we just need to pick the nums[i] and nums[j], for -nums[k] we can get that number from hashtable

# Using hashtable + set data structure
1. Construct the hashtable with key = nums[k] and value = how many times that number appear in nums array 
2. Loop from first index of nums until last index of nums to construct the hashtable
3. intialize two pointer (i and j)
4. Loop from first index of nums until last index of nums
   - if nums[i] + nums[j] appear in the hashtable
     - put those numbers in set data structure
5. Loop for every data in set data structure and put into the answer arrays
6. return the answer arrays

Time Complexity : O(N * N * logM)
N -> size of nums
M -> size of set data structure

Memory ComplexitY : O(log M)
M -> size of set data stucture

What make second solution run slowly ? 
1. because for every combination we need to input that into the set datastructure, which take log M time complexity

How to improve the solution 
1. Sort the array nums in the first place

# Using hashtable + sort
1. sort the nums of array
2. construct hashtable with key = nums, and value = how many times that number appear
3. intialize two pointer (i and j)
4. Loop from first index of nums until last index of nums
   - if (nums[i] + nums[j]) * -1 appear in the hashtable
     - put those numbers in the answer array
5. Loop for every data in set data structure and put into the answer arrays

Time Compleixty : O(N log N + N^2)
N -> size of nums

Memory Complexity : O(M)
M -> size of set

What makes that algorithm slowly ? 
1. Is because we are using a hashmap to get the answer which can introduce O(M) time complexity

How to improve ? 
1. Just throw the hashmap and ues two pointer technique like in 2sum sorted problem

# Using two pointer
1. Loop from the first index of array until last index of array
2. if there is duplicate number, we can skip the number, since we need to return unique value
3. initialize left and right pointer
4. left = i + 1 and right = nums.size() - 1
5. while left pointer less than right pointer, we need to do these steps
   - skip the duplicate number
   - if nums[left] + nums[right] > target, then decrease the right pointer by 1
   - if nums[left] + nums[right] < target, then decrease the left pointer by 1
   - if nums[left] == nums[right]
     - add to answer variable
     - increaes left pointer by 1
     - skip the duplicate number

Time Complexity : O(N^2)
N -> size of nums

Memory complexity : O(1)

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            // skip the duplicate number
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int threeSum = nums[i] + nums[left] + nums[right];

                if (left > i + 1 && nums[left] == nums[left - 1]) {
                    left++;
                    continue;
                }

                if (threeSum > 0) {
                    right--;
                } else if (threeSum < 0) {
                    left++;
                } else {
                    answer.push_back({nums[i], nums[left], nums[right]});
                    left++;
                }
            }
        }

        return answer;
    }
};