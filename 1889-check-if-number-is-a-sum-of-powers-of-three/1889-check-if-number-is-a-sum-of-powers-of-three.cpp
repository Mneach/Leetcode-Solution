class Solution {
public:

    bool dfs(vector<int> &bucket, int reminder, int index) {
        if (reminder < 0) return false;
        else if (reminder == 0) return true;

        for (int i = index; i < bucket.size(); i++) {
            bool result = dfs(bucket, reminder - bucket[i], i + 1);

            if (result == true) return result;
        }

        return false;
    }

    bool checkPowersOfThree(int n) {
        vector<int> bucket;
        int current = 0;
        int result = 0;

        while (result < 1e7 + 1) {
            result = pow(3, current);
            current++;
            bucket.push_back(result);
        }

        return dfs(bucket, n, 0);
    }
};