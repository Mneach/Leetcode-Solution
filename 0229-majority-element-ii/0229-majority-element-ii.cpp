/*

How to solve the problem : 

# Hash table approach
1. loop for every number in nums array
2. put nums[i] intp hashtable with key = nums[i] and value = total of number x in that nums of array
3. put all of the numbers that appear more than n / 3 into array of answers

Time complexity : O(N)
where N -> size of nums array

Memory complexity : O(N)
where N -> size of nums array

*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> answer;
        unordered_map<int,int> bucket; 

        for (int i = 0; i < nums.size(); i++) {
            int number = nums[i];
            bucket[number]++;
        }

        int totalMinimum = nums.size() / 3;
        for (auto data : bucket) {
            int key = data.first;
            int value = data.second;

            if (value > totalMinimum) {
                answer.push_back(key);
            }
        }

        return answer;
    }
};