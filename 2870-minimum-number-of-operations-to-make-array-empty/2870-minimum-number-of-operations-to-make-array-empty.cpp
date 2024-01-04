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
            int count2 = 0;
            int count3 = 0;
            int tempValue = data.second;

            while(tempValue > 0){
                if(tempValue % 3 == 0){
                    count3 = tempValue / 3;
                    break;
                }
                count2++;
                tempValue -= 2;
            }

            if(tempValue < 0){
                valid = false;
                break;
            }else{
                answer += count2 + count3;
            }
        }
        
        if(valid) return answer;
        else return -1;
    }
};