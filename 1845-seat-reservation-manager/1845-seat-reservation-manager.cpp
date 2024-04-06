class SeatManager {
public:

    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_map<int,int> ump;
    
    int marker;
    SeatManager(int n) {
        marker = 1;
    }
    
    int reserve() {
        if(pq.empty() == false){
            int res = pq.top();
            pq.pop();
            
            return res;
        }
        
        int res = marker;
        marker++;
        
        return res;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */