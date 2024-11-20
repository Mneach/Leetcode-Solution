class Solution {
public:
    // Check if it's possible to satisfy the condition with a total length `l` and taking `k` characters
    bool isValidLength(const std::vector<std::vector<int>>& pref, const std::vector<std::vector<int>>& suff, int l, int k) {
        for (int i = 0; i <= l; ++i) {
            bool isValid = true;
            for (int j = 0; j < 3; ++j) {
                if (pref[i][j] + suff[suff.size() - 1 - (l - i)][j] < k) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) return true;
        }
        return false;
    }

    int takeCharacters(const std::string& s, int k) {
        int n = s.size();

        // Compute prefix and suffix character counts
        std::vector<std::vector<int>> pref(n + 1, std::vector<int>(3, 0));
        std::vector<std::vector<int>> suff(n + 1, std::vector<int>(3, 0));

        for (int i = 1; i <= n; ++i) {
            pref[i] = pref[i - 1];
            ++pref[i][s[i - 1] - 'a'];
        }

        for (int i = n - 1; i >= 0; --i) {
            suff[i] = suff[i + 1];
            ++suff[i][s[i] - 'a'];
        }

        // Binary search for the minimum valid length
        int left = -1, right = n + 1;
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            if (isValidLength(pref, suff, mid, k)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        return (right == n + 1) ? -1 : right;
    }
};
