class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        map<int,int> mp;
        
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[i].size(); j++){
                mp[mat[i][j]]++;
            }
        }
        
        for(auto data : mp){
            if(data.second == mat.size()){
                return data.first;
            }
        }
        
        return -1;
    }
};