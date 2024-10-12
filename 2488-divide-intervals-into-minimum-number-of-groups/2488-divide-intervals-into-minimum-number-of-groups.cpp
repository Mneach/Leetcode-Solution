class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), []( const vector<int> first, const vector<int> second){

            if(first[0] == second[0]){
                return first[1] < second[1];
            }else{
                return first[0] < second[0];
            }
        });

        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto data : intervals){
            int start = data[0];
            int end = data[1];

            if(pq.empty()){
                pq.push(end);
            }else if(pq.top() < start){
                pq.pop();
                pq.push(end);
            }else if(pq.top() >= start){
                pq.push(end);
            }
        }

        return pq.size();
    }
};