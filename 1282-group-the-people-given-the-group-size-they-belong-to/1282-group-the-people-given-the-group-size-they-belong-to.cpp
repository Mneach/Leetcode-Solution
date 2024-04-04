class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
        map<int,vector<int>> mp;
        
        for(int i = 0; i < groupSizes.size(); i++){
            mp[groupSizes[i]].push_back(i);
        }
        
        vector<vector<int>> answer;
        
        for(auto data : mp){
            
            int start = 0;
            while(start < data.second.size()){
                
                vector<int> temp;
                int current = start;
                for(int i = start; i < current + data.first && start < data.second.size(); i++){
                    temp.push_back(data.second[i]);
                    start++;
                }

                if(temp.size() > 0){
                    answer.push_back(temp);
                }
            }
        }
        
        return answer;
    }
};