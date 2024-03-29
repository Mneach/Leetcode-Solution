class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
       
       sort(points.begin(), points.end(), [](vector<int> &first, vector<int> &second){
           return first[0] > second[0];
       });
      
       int answer = 0;
       for(int i = 0; i < points.size() - 1; i++){
          answer = max(answer, points[i][0] - points[i + 1][0]); 
       }
         
        return answer;
    }
};