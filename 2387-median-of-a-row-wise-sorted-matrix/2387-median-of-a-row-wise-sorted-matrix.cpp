class Solution {
public:
    int matrixMedian(vector<vector<int>>& grid) {
        int left = 1;
        int right = 1000000;
        
        int middlePoint = grid.size() * grid[0].size() / 2;
        
        while(left < right){
            int mid = (left + right) / 2;
            int numberOfLarger = 0;
            
            for(auto v : grid){
                numberOfLarger += v.end() - upper_bound(v.begin(), v.end(), mid);
            }
            
            if(numberOfLarger > middlePoint){
                left = mid + 1;
            }else{
                right = mid;
            }
            
            cout << left << " " << mid << " " << right << endl;
        }
        
        return left;
    }
};