class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        
        int currentMax = 0;
        int index = 0;
        for(int i = 0; i < grid.size(); i++){
            int total = 0;

            for(auto number : grid[i]) total += number;

            if(total > currentMax){
                currentMax = total;
                index = i;
            }
        }

        return index;
    }
};