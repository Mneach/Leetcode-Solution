class Solution {
public:
    int secondHighest(string s) {
        vector<int> bucket(10, 0);

        for (auto c : s) {
            if (c >= '0' && c <= '9') {
                bucket[c - '0']++;
            }
        }

        bool first = true;
        for (int i = bucket.size() - 1; i >= 0; i--) {
            if (bucket[i] > 0 && first) {
                first = false;
            } else if (bucket[i]) {
                return i;
            }
        }

        return -1;
    }
};