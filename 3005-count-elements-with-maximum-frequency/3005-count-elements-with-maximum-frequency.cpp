class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        map<int,int> mp;
        
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        
        int maxFreq = 0;
        for(auto data : mp){
            maxFreq = max(maxFreq, data.second);
        }
        
        int answer = 0;
        
        for(auto data : mp){
            if(maxFreq == data.second){
                answer += data.second;
            }
        }
        
        return answer;
    }
};