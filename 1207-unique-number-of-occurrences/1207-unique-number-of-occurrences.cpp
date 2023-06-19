class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map;
        set<int> answer;
        
        for(int i = 0; i < arr.size(); i++){
            map[arr[i]]++;
        }
        
        for(auto x : map){
            answer.insert(x.second);
        }
        
        return answer.size() == map.size();
    }
};