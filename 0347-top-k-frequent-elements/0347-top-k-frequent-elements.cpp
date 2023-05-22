class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int , int> map;
        
        for(int i = 0; i < nums.size(); i++){
            if(map[nums[i]]){
                map[nums[i]]++;
            }else{
                map[nums[i]] = 1;
            }
        }
    
        vector<pair<int , int>> vec(map.begin(), map.end());
        
        sort(vec.begin(), vec.end(), [](const auto &a , const auto &b){
            return a.second > b.second;
        });
        
        vector<int> answer;

        int currentIndex = 1;
        
        for(auto x : vec){
            answer.push_back(x.first);
            if(currentIndex == k) break;
            currentIndex++;
        }
        
        return answer;       
    }
                  
};