class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> ump1;
        unordered_map<int,int> ump2;
        vector<int> answer;
        
        for(auto data : nums1) ump1[data]++;
        for(auto data : nums2) ump2[data]++;

        for(auto data : ump1){
            int key = data.first;
            int value = data.second;

            if(ump2[key] > 0){
                int total = min(value, ump2[key]);
                while(total > 0){
                    answer.push_back(key);
                    total--;
                }
            }
        }
        
        return answer;
    }
};