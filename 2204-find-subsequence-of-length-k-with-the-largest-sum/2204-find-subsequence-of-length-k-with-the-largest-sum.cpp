class Compare {
public:
    bool operator()(pair<int,int> first, pair<int,int> second) {
        return first.first > second.first;
    }
};

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> answer;
        vector<pair<int,int>> vp;
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;

        for (int i = 0; i < nums.size(); i++) {
            if (pq.size() != k) {
                pq.push({nums[i], i});
            } else if (pq.top().first < nums[i]){
                pq.pop();
                pq.push({nums[i], i});
            }
        }

        while(pq.size() > 0) {
            auto data = pq.top();
            pq.pop();
            vp.push_back(data);
        }

        sort(vp.begin(), vp.end(), [](pair<int,int> first, pair<int,int> second){
           return first.second < second.second;
        });

        for (auto data : vp) {
            int number = data.first;
            answer.push_back(number);
        }

        return answer;
    }
};