class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int answer = 0;
        sort(meetings.begin(), meetings.end());
        
        // first = start
        // second = end;
        int temp = meetings[0][1];
        
        if(meetings[0][0] != 1){
            answer += meetings[0][0] - 1;
        }
        
        for(int i = 1; i < meetings.size(); i++){
            
            int start = meetings[i][0];
            int end = meetings[i][1];
            
            if(temp < start){
                // not intersact
                answer = answer + (start - temp) - 1;
                temp = end;
            }else if(temp >= start){
                // intersact
                temp = max(temp, end);
            }
        }
        
        // count for reminder day
        answer = answer + (days - temp);
        
        return answer;
    }
};