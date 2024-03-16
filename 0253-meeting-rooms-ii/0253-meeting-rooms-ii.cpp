class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> roomsEnd;
        
        sort(intervals.begin(), intervals.end());
        
        for(int i = 0; i < intervals.size(); i++){
            int left = intervals[i][0];
            int right = intervals[i][1];
            
            if(i == 0){
                roomsEnd.push(right);
            }else{
                
                if(roomsEnd.top() <= left){
                    roomsEnd.pop();
                    roomsEnd.push(right);
                }else{
                    roomsEnd.push(right);
                }
            }
        }
        
        return roomsEnd.size();
    }
};