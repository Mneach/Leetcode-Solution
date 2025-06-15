class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        return min(unordered_set<int>(begin(candyType), end(candyType)).size(), candyType.size() / 2);
    }
};