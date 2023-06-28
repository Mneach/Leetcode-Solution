class RecentCounter {
public:
    
    queue<int> calls;
    RecentCounter() {

    }
    
    int ping(int t) {
        if(calls.empty()){
            calls.push(t);
        }else{
            calls.push(t);
            while(calls.empty() == false && t - 3000 > calls.front()){
                calls.pop();
            }
        }
        
        return calls.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */