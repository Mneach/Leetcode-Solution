class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        unordered_map<int,int> ump;
        set<pair<int,int>> answer;

        for(auto data : nums){
            ump[data]++;
        }

        int limit = k == 0 ? 1 : 0;

        for(auto data : nums){
            int find1 = data - k;
            int find2 = data + k;

            if(ump[find1] > limit && ump[find2] > limit){
                answer.insert(make_pair(min(data, find1), max(data, find1)));
                answer.insert(make_pair(min(data, find2), max(data, find2)));
            }else if(ump[find1] > limit){
                answer.insert(make_pair(min(data, find1), max(data, find1)));
            }else if(ump[find2] > limit){
                answer.insert(make_pair(min(data, find2), max(data, find2)));
            }
        }

        return answer.size();
    }
};