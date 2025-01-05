class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long int total = 0;

        for (auto shift : shifts) total += shift;

        for (int i = 0; i < s.length(); i++) {
            int ascii = s[i] - 'a';
            s[i] = ((ascii + (total % 26)) % 26) + 'a';
            total -= shifts[i];
        }
        
        return s;
    }
};