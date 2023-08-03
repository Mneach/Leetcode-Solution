class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        if(firstList.size() == 0 || secondList.size() == 0) return {};
        
        
        int indexFirst = 0;
        int indexSecond = 0;
       
        vector<vector<int>> result;
        while(indexFirst < firstList.size() && indexSecond < secondList.size()){
            
            if(firstList[indexFirst][0] > secondList[indexSecond][1]){
                indexSecond++;
                continue;
            }else if(secondList[indexSecond][0] > firstList[indexFirst][1]){
                indexFirst++;
                continue;
            }
            
            int x = max(firstList[indexFirst][0], secondList[indexSecond][0]);
            int y = min(firstList[indexFirst][1], secondList[indexSecond][1]);
            result.push_back({x , y});
            
            if(firstList[indexFirst][1] > secondList[indexSecond][1]){
                indexSecond++; 
            }else{
                indexFirst++;
            }
            
            // cout << x << " " << y << endl;
        }
        
        return result; 
    }
};