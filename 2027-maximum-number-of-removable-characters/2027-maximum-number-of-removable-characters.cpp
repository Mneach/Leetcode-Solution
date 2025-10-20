class Solution {
private:
    bool isValid(string s, string &p, vector<int> &removable, int k) {
        bool result = false;

        for (int i = 0; i < k; i++) {
            s[removable[i]] = 'X';
        }

        int i = 0;
        int j = 0;

        while (i < s.length() && j < p.length()) {
            if (s[i] == p[j]) {
                j++;
            }
            i++;
        }

        if (j == p.length()) {
            result = true;
        }

        return result;
    }
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
       int minimumK = 0; 
       int maximumK = removable.size();
       int result = 0;

       while (minimumK <= maximumK) {
            int k = minimumK + (maximumK - minimumK) / 2;

            // check if k is a valid answer
            if (isValid(s, p, removable, k)) {
                result = k;
                minimumK = k + 1;
            } else {
                maximumK = k - 1;
            }
       }

       return result;
    }
};