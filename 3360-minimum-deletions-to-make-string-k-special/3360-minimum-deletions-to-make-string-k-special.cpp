class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int> bucket;
        int answer = INT_MAX;

        for (auto c : word) {
            bucket[c]++;
        }

        for (auto current : bucket) {
            int deleted = 0;
            for (auto next : bucket) {
                if (current.second > next.second) {
                    deleted += next.second;
                } else if (next.second > current.second + k) {
                    deleted += next.second - (current.second + k);
                }
            }
            answer = min(deleted, answer);
        }

        return answer;
    }
};