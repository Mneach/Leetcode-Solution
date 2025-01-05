class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long int total = accumulate(shifts.begin(), shifts.end(), 0LL);

        for (int i = 0; i < s.length(); i++) {
            int ascii = s[i] - 'a';
            s[i] = ((ascii + (total % 26)) % 26) + 'a';
            total -= shifts[i];
        }
        
        return s;
    }
};