class Solution {
private:
    vector<string> getWords(string s) {
        vector<string> result;
        string temp = "";

        for (auto c : s) {
            if (c == ' ') {
                result.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }

        result.push_back(temp);

        return result;
    }
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if (sentence1.length() < sentence2.length()) {
            swap(sentence2, sentence1);
        }

        vector<string> s1 = getWords(sentence1);
        vector<string> s2 = getWords(sentence2);

        int l1 = 0;
        int r1 = s1.size() - 1;
        int l2 = 0;
        int r2 = s2.size() - 1;

        // move the left poinetr
        while (l1 < s1.size() && l2 < s2.size() && s1[l1] == s2[l2]) {
            l1++;
            l2++;
        }

        // move the right pointer
        while (r1 >= 0 && r2 >= 0 && s1[r1] == s2[r2]) {
            r1--;
            r2--;
        }

        return l2 > r2;
    }
};