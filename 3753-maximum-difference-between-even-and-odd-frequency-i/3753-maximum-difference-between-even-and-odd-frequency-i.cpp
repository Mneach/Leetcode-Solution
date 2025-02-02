class Solution {
public:
    int maxDifference(string s) {

        vector<int> bucket(26, 0);
        
        for (int i = 0; i < s.length(); i++) {

            int index = s[i] - 'a';
            bucket[index]++;
        }

        int odd = INT_MIN;
        int even = INT_MAX;

        for (int i = 0; i < bucket.size(); i++) {
            if (bucket[i] % 2 == 0 && bucket[i] > 0) {
                even = min(even, bucket[i]);
            } else {
                odd = max(odd, bucket[i]);
            }
        }

        return odd - even;
    }
};