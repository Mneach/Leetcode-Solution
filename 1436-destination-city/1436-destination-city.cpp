class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, string> mp;
        vector<string> arr;
        
        
        for(int i = 0; i < paths.size(); i++){
           mp[paths[i][0]] = paths[i][1];
           arr.push_back(paths[i][1]);
        }
        
        for(int i = 0; i < arr.size(); i++){
            if(mp.count(arr[i]) <= 0){
                return arr[i];
            }
        }
        
        return "";
    }
};