class Solution {
public:
    int maxUniqueSplit(const string& s) {
        unordered_set<string> seen;
        return backtrack(s, 0, seen);
    }

private:
    int backtrack(const string& s, int start, unordered_set<string>& seen) {
        if (start == s.size()) {
            return 0; // No more substrings to add
        }

        int maxCount = 0;

        for (int end = start + 1; end <= s.size(); ++end) {
            string substring = s.substr(start, end - start);

            if (seen.insert(substring).second) { // Inserts and checks uniqueness in one step
                maxCount = max(maxCount, 1 + backtrack(s, end, seen));
                seen.erase(substring); // Backtrack by removing the substring
            }
        }
        return maxCount;
    }
};
;