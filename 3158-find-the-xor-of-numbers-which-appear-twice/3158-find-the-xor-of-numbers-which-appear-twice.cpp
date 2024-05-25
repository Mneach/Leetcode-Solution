class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int,int> ump;
        
        for(auto data : nums){
            ump[data]++;
        }
        
        int answer = 0;
        for(auto data : ump){
            if(data.second == 2){
                answer ^= data.first;
            }
        }
        
        return answer;
    }
};