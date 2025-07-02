class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> bucket;
        for (auto num : nums) {
            bucket[num]++;
        }

        priority_queue<pair<int,int>> pq;

        for (auto data : bucket) {
            int key = data.first;
            int value = data.second;

            pq.push({value, key});
        }

        vector<int> answer;
        while(k > 0 && pq.size() > 0) {
            k--;
            auto data = pq.top();
            int number = data.second;
            answer.push_back(number);
            pq.pop();
        }

        return answer;
    }
};