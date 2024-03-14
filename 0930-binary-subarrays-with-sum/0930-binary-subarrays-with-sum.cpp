class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int answer = 0;
        int currentSum = 0;
        
        map<int,int> mp;
        
        for(auto data : nums){
            currentSum += data;
            
            if(currentSum == goal) answer++;
            
            if(mp.find(currentSum - goal) != mp.end()) answer += mp[currentSum - goal];
            
            mp[currentSum]++;
        }
        
        return answer;
    }
};