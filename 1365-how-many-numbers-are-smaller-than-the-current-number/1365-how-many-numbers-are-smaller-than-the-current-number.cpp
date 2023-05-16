class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        map<int, int> temp;
        
        for(int i = 0; i < nums.size(); i++){
            if(temp[nums[i]]) temp[nums[i]] = temp[nums[i]] + 1;
            else temp[nums[i]] = 1;
        }
        
        vector<int> answer;
        for(int i = 0; i < nums.size(); i++){
            
            int tempTotal = 0;
            for(auto x : temp){
                if(x.first == nums[i]) break;
                tempTotal += x.second;
            }
            
            answer.push_back(tempTotal);
        }
        
        return answer;
    }
};