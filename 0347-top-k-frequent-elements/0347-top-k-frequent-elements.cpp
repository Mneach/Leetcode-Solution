class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> bucket;
        vector<int> answer;
        for (auto num : nums) bucket[num]++;

        priority_queue<pair<int,int>> pq;

        for (auto data : bucket) {
            pq.push({data.second, data.first});
        }

        while (k > 0 && pq.size() > 0) {
            answer.push_back({pq.top().second});
            k--;
            pq.pop();
        }

        return answer;
    }
};