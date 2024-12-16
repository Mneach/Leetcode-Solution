
struct Compare {

    bool operator()(pair<int,int> &first, pair<int,int> &second) {

        if (first.first == second.first) {
            return first.second > second.second;
        }

        return first.first > second.first;
    }
};

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
        vector<int> answer(nums.size(), 0);

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            pq.push({num, i});
        }

        while (k > 0) {
            auto [num, index] = pq.top();
            pq.pop();

            pq.push({num * multiplier, index});
            k--;
        }

        while (pq.size() > 0) {
            auto [num, index] = pq.top();
            pq.pop();

            answer[index] = num;
        }

        return answer;
    }
};