class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int> mp;
        
        mp[0] = -1;
        
        int count = 0;
        int answer = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1) count++;
            else count--;
            
            if(mp.count(count) > 0){
                answer = max(answer, i - mp[count]);
            }else{
                mp[count] = i;
            }
        }
        
        return answer;
    }
};