class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> ump;
        ump[0] = -1;

        int total = 0;

        for(int i = 0; i < nums.size(); i++){
            total += nums[i];
            int reminder = total % k;
            
            if(ump.find(reminder)!=ump.end()){
                if(i - ump[reminder] > 1) {
                    return true;
                }
            }else{
                ump[reminder] = i;
            }
            
        }

        return false;
    }
};