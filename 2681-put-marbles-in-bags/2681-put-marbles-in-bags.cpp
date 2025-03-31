class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        long long answer = 0;
        vector<long long> bucket(weights.size() - 1, 0);

        for (int i = 0; i < weights.size() - 1; i++) {
            bucket[i] += weights[i] + weights[i + 1];
        }

        sort(bucket.begin(), bucket.end());

        for (int i = 0; i < k - 1; i++) {
            answer += bucket[weights.size() - 2 - i] - bucket[i];
        }

        return answer;
    }
};