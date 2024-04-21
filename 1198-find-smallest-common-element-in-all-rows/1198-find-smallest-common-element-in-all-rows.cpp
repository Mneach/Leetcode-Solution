class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        vector<int> pos(mat.size());
        
        for(int j = 0; j < mat[0].size(); j++){
            bool found = true;
            
            for(int i = 1; i < mat.size() && found; i++){
                pos[i] = lower_bound(mat[i].begin() + pos[i], mat[i].end(), mat[0][j]) - mat[i].begin();
                
                if(pos[i] >= mat[0].size()) return -1;
                
                found = mat[i][pos[i]] == mat[0][j];
            }
            
            if(found){
                return mat[0][j];
            }
        }
        
        return -1;
    }
};