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

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int> hashTable;
        vector<vector<int>> answer;
        
        sort(nums.begin(), nums.end());

        for (auto data : nums) {
            hashTable[data]++;
        }

        for (int i = 0; i < nums.size(); i++) {
            int first = nums[i];
            hashTable[first]--;

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < nums.size(); j++) {
                int second = nums[j];
                hashTable[second]--;

                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int third = (first + second) * -1;
                if(hashTable[third] > 0) {
                    int minimum = min(first, min(second, third));
                    int maximum = max(first, max(second, third));
                    int middle = first + second + third - minimum - maximum;

                    answer.push_back({minimum, middle, maximum});
                }
            }

            // readding the data into the hashtable
            for (int j = i + 1; j < nums.size(); j++) {
                hashTable[nums[j]]++;
            }
        }

        return answer;
    }
};