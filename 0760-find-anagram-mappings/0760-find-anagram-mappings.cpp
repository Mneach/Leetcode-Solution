class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        map<int,stack<int>> bucket;
        
        for(int i = 0; i < nums2.size(); i++){
            bucket[nums2[i]].push(i);
        }
        
        vector<int> answer(nums1.size());
        for(int i = 0; i < nums1.size(); i++){
            answer[i] = bucket[nums1[i]].top();
            bucket[nums1[i]].pop();
        }
        
        return answer;
    }
};