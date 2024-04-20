class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
        vector<int> answer(intervals.size(), -1);
        map<vector<int>,int> ump;
        
        for(int i = 0; i < intervals.size(); i++){
            ump[intervals[i]] = i;
        }
        
        sort(intervals.begin(), intervals.end());
        
        for(int i = 0; i < intervals.size(); i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            int left = i;
            int right = intervals.size() - 1;
            int answerIndex = intervals.size();
            
            while(left <= right){
                int mid = left + (right - left) / 2;
               
                if(intervals[mid][0] < end){
                    left = mid + 1;
                    if(intervals[mid][0] >= end) answerIndex = min(answerIndex, mid);
                }else {
                    right = mid - 1;
                    if(intervals[mid][0] >= end) answerIndex = min(answerIndex, mid);
                }
            }
            
            if(answerIndex >= 0 && answerIndex < intervals.size()){
                answer[ump[intervals[i]]] = ump[intervals[answerIndex]];
            }else{
                answer[ump[intervals[i]]] = -1;
            }
            
        }
        
        return answer;
    }
};