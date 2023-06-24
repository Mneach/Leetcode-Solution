class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0) return 0;
        
        set<int> result;
        
        for(int i = 0; i < nums.size(); i++) result.insert(nums[i]);
        
        int answer = 1;
        int current = 1;
        long long prev = LONG_LONG_MIN;
        for(auto x : result){
            if(prev != LONG_LONG_MIN){
                if(x == prev + 1) current++;
                answer = max(answer, current);
                
                if(x != prev + 1) current = 1;
            }
            
            prev = x;
        }
        
        return answer;
    }
};