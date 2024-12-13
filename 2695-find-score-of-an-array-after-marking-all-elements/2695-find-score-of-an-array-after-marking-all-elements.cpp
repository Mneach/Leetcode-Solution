
struct Compare {
public:
    bool operator()(pair<int,int> &first, pair<int,int> &second){
        if (first.first == second.first) {
            return first.second > second.second;
        } else {
            return first.first > second.first;
        }
    }
};

class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long answer = 0;   

        vector<bool> visited(1e5 + 2, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];

            pq.push({num, i});
        }

        while(pq.size() > 0) {
            auto [num, index] = pq.top();
            pq.pop();

            if (visited[index] == true) continue;

            // mark adject cell as visited
            visited[index] = true;
            visited[index + 1] = true;

            if (index > 0) {
                visited[index - 1] = true;
            }

            answer += num;
        }

        return answer;
    }
};