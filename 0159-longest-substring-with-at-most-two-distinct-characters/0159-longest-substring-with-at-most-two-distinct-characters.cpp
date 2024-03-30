class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        
        unordered_map<int,int> ump;
        
        int answer = 0;
        int left = 0;
        for(int right = 0; right < s.length(); right++){
            
            
            ump[s[right]]++;
            
            if(ump.size() > 2){
                while(left < right && ump.size() > 2){
                    ump[s[left]]--;
                    
                    if(ump[s[left]] == 0){
                        ump.erase(s[left]);
                    }
                    left++;
                }
            }
            answer = max(answer, right - left + 1);
        }
        
        return answer;
    }
};