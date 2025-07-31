class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res;
        unordered_set<int> current;
        unordered_set<int> current2;

        for (auto i : arr) {
            current2 = {i};

            for (auto j : current) current2.insert(i | j);
            for (auto j : current = current2) res.insert(j);
        }

        return res.size();
    }
};