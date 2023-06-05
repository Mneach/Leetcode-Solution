class Solution {
public:
    
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        bool answer = true;
        int size = coordinates.size();
      
        for(int i = 2; i < size; i++){
            int x2 = coordinates[i][0];
            int y2 = coordinates[i][1];
            int x1 = coordinates[i - 1][0];
            int y1 = coordinates[i - 1][1];
            int x = coordinates[i - 2][0];
            int y = coordinates[i- 2][1];
            
            int diff1 = (y2 - y1) * (x1 - x);
            int diff2 = (y1 - y) * (x2 - x1);
            
            if(diff1 != diff2) return false;
        }
        
        return answer;
    }
};