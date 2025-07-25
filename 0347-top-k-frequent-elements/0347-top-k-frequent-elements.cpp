/*

How to solve : 
1. count the number frequency using hash tabel
2. put into the array based on the number frequency
3. get the answer until current answer size == k

Time complexity : O(N)
Memory complexity : O(N)

*/


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counter;
        vector<vector<int>> bucket(nums.size() + 1);
        vector<int> answer;

        for (auto num : nums) counter[num]++;
        
        for (auto data : counter) {
            int key = data.first;
            int value = data.second;
            
            bucket[value].push_back(key);
        }

        for (int i = bucket.size() - 1; i >= 0 && answer.size() < k; i--) {
            if (bucket[i].size() != 0) {
                answer.insert(answer.end(), bucket[i].begin(), bucket[i].end());
            }
        }

        return answer;
    }
};