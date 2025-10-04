class Solution {
public:
    int characterReplacement(string s, int k) {
        int result = 0;
        vector<int> bucket(26, 0);
        int left = 0;
        int right = 0;

        while (right < s.length()) {
            int ascii = s[right] - 'A';
            bucket[ascii]++;

            int maximum = 0;
            int total = 0;
            for (auto data : bucket) {
                total += data;
                maximum = max(maximum, data);
            }

            total -= maximum;

            while (total > k) {
                bucket[s[left] - 'A']--;
                maximum = 0;
                total = 0;

                for (auto data : bucket) {
                    total += data;
                    maximum = max(maximum, data);
                }
                
                total -= maximum;
                left++;
            }

            // cout << left << " " << right << endl;

            result = max(result, (right - left) + 1);
            right++;
        }

        return result;
    }
};