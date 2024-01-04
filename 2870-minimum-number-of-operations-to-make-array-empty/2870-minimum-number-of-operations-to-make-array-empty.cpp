class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        map<int,int> mp;
        
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        
        bool valid = true;
        int answer = 0;
        for(auto data : mp){
            if(data.second == 1){
                valid = false;
                break;
            }else{
                answer += ceil(double(data.second) / 3);
            }
        }
        
        if(valid) return answer;
        else return -1;
    }
};