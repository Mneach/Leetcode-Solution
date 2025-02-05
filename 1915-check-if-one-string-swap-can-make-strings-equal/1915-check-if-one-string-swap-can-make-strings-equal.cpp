class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> swap;

        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                swap.push_back(i);
            }
        }

        if (swap.size() == 1 || swap.size() > 2) return false;
        else if (swap.size() == 0) return true;

        int first = swap[0];
        int second = swap[1];
        int temp = s1[first];
        s1[first] = s1[second];
        s1[second] = temp;

        return s1 == s2;
    }
};