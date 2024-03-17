class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> answer;
        
        if(intervals.size() == 0){
            return {newInterval};
        }
        
        int left = 0;
        int right = intervals.size() - 1;
        int target = newInterval[0];
        
        while(left <= right){
            int mid = (left + right) / 2;
            
            if(intervals[mid][0] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        
        intervals.insert(intervals.begin() + left, newInterval);
        
        for(auto data : intervals){
            
            if(answer.size() == 0 || answer.back()[1] < data[0]){
                answer.push_back(data);
            }else{
                answer.back()[1] = max(answer.back()[1], data[1]);
            }
        }
        
        return answer;
    }
};