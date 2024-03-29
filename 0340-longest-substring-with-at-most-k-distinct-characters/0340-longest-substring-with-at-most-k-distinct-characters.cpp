class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        if(k == 0) return 0;
        
        unordered_map<int,int> ump;
        int size = s.length();
        
        int answer = 0;
        int left = 0;
        
        for(int right = 0; right < size; right++){
           
            ump[s[right]]++;
            
            if(ump.size() > k){
                while(left < right && ump.size() > k){
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