class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        map<int,int> mp;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                mp[nums[i]]++;
            }
        }
        
        int answer = 1;
        
        for(auto data : mp){
            if(data.first == answer){
                answer++;
            }else{
                return answer;
            }
        }
        
        return answer;
    }
};