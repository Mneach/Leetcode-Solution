class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> ump;

        for(auto data : nums) ump[data]++;

        sort(nums.begin(), nums.end(), [&](int p1, int p2){
            if(ump[p1] == ump[p2]){
                return p1 > p2;
            }else{
                return ump[p1] < ump[p2];
            }
        });

        return nums;
    }
};