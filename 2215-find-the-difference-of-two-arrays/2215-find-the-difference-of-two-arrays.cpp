class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
        vector<vector<int>> answer(2);
        
        set<int> setNums1;
        set<int> setNums2;
        
        for(int i = 0; i < nums1.size(); i++) setNums1.insert(nums1[i]);
        for(int i = 0; i < nums2.size(); i++) setNums2.insert(nums2[i]);
        
        for(auto x : setNums1) map[x]++;
        for(auto x : setNums2) map[x]++;
        
        for(auto x : setNums1) if(map[x] == 1) answer[0].push_back(x);
        for(auto x : setNums2) if(map[x] == 1) answer[1].push_back(x);
        
        return answer;
    }
};