class Solution {
public:

    long long max(long long a, long long b) {
        if (a > b) return a;
        else return b;
    }

    long long dfs(vector<vector<int>> &questions, vector<long long> &bucket, int index) {
        if (index >= bucket.size()) return 0;

        if (bucket[index] != -1) {
            return bucket[index];
        }

        // dp state = skip or take
        int score = questions[index][0];
        int brainPower = questions[index][1];
        bucket[index] = max(
            dfs(questions, bucket, index + 1), // skip
            score + dfs(questions, bucket, index + brainPower + 1) // take
        );

        return bucket[index];
    }

    long long mostPoints(vector<vector<int>>& questions) {
        long long answer = 0;
        vector<long long> bucket(questions.size(), -1);

        return dfs(questions, bucket, 0);
    }
};