class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> ans;
        int i = 0, N = S.length(); // i is the start of each group
        for (int j = 0; j < N; ++j) {
            if (j == N-1 || S[j] != S[j+1]) {
                // Here, [i, j] represents a group.
                if (j-i+1 >= 3)
                    ans.push_back({i, j});
                i = j + 1;
            }
        }
        return ans;
    }
};