class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        
        map<int,int> mp;

        for(auto data : nums) mp[data]++;


        int answer = -1;
        for(auto data : mp){
            if(data.second == 1){
                answer = max(answer, data.first);
            }
        }

        return answer;
    }
};