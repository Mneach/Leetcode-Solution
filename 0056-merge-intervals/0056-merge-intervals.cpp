class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> answer;
        sort(intervals.begin(), intervals.end());
        
        int currentStart = intervals[0][0];
        int currentEnd = intervals[0][1];
        
        for(int i = 0; i < intervals.size(); i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            if(start >= currentStart && start <= currentEnd){
                currentEnd = max(end, currentEnd);
            }else{
                answer.push_back({currentStart, currentEnd});
                currentStart = start;
                currentEnd = end;
            }
        }
        
        answer.push_back({currentStart, currentEnd});
        
        return answer;
    }
};