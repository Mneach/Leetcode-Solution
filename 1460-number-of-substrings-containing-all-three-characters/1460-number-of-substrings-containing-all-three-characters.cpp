class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq(3, 0);
        int left = 0, total = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            freq[s[right] - 'a']++;
            
            while (freq[0] && freq[1] && freq[2]) {
                total += s.length() - right;
                freq[s[left++] - 'a']--;
            }
        }
        
        return total;
    }
};