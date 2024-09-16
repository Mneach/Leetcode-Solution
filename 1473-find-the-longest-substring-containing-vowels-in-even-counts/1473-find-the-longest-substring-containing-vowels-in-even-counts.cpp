class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> ump;
        int mask = 0;
        int answer = 0;
        
        ump[0] = -1;
        
        for (int index = 0; index < s.size(); ++index) {
            char c = s[index];
            
            if (c == 'a') mask ^= (1 << 0); 
            if (c == 'e') mask ^= (1 << 1); 
            if (c == 'i') mask ^= (1 << 2); 
            if (c == 'o') mask ^= (1 << 3); 
            if (c == 'u') mask ^= (1 << 4); 
            
            if (ump.find(mask) != ump.end()) {
                answer = max(answer, index - ump[mask]);
            } else {
                ump[mask] = index;
            }
        }
        
        return answer;
    }
};
