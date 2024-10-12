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

/*

Intuitinon : 
we need to make another group if the end interval in the current group is more than the current end

# Implementation : sorting + priority queue
- sorting the data and make sure if we put from the lowest to the highest start
- that is important to construct the answer
- use proiority queue to save the end interval for every group
- if priority queue top is less than start, that mean we dont need to create anotther group, we can put that data into that group, and update the end interval of that group
- othwerise create another group by pushing the data into the prioriy queue

*/