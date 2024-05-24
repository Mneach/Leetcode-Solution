class Solution {
public:
    int hIndex(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int> > pq;
        
        for(auto data : arr){
            pq.push(data);
        }
        
        while(pq.empty() == false){
            int totalPaper = pq.size();
            
            if(pq.top() >= totalPaper){
                return pq.size();
            }else{
                pq.pop();
            }
        }
        
        return 0;
    }
};