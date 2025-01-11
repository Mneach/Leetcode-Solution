class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k) return false;

        vector<int> arr(26, 0);

        for (auto c : s) {
            int ascii = c - 'a';

            arr[ascii]++;
        }

        int totalOdd = 0;
        int totalEven = 0;
        int total = 0;
        for (int i = 0; i < 26; i++) {
            if (arr[i] == 0) continue;

            if (arr[i] % 2 == 0) totalEven++;
            else totalOdd++;

            total += arr[i];
        }

        int maximum = total;

        int minimum;
        if (totalOdd >= totalEven) {
            minimum = totalEven + (totalOdd - totalEven);
        } else {
            minimum = totalOdd;
        }

        return minimum <= k && k <= maximum;
    }
};