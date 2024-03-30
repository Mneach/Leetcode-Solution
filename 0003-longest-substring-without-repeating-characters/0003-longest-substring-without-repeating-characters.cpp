class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<int,int> ump;
        
        int answer = 0;
        int left = 0;
        
        for(int right = 0; right < s.length(); right++){
            
            ump[s[right]]++;
            
            if(ump[s[right]] > 1){
                while(left < right && ump[s[right]] != 1){
                    ump[s[left]]--;
                    left++;
                }
            }
            
            answer = max(answer, right - left + 1);
        }
        
        return answer;
    }
};