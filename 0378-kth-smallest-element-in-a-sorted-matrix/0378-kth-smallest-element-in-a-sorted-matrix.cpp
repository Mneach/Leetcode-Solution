class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
       int row = matrix.size();
       int col = matrix[0].size();
       vector<int> vc;
        for(int i = 0 ; i< row ;i++){
            for(int j =0 ; j< col ; j++){
              vc.push_back(matrix[i][j]);
            }
        }
        sort(vc.begin(),vc.end());

        return vc[k-1]; 
    }
};