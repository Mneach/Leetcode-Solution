class SmallestInfiniteSet {
public:
    
    priority_queue<int, vector<int>, greater<int> > arrDesc;
    unordered_map<int,int> mp;
    SmallestInfiniteSet() {
       for(int i = 1; i <= 1000; i++){
           arrDesc.push(i);
       } 
    }
    
    int popSmallest() {
        int temp = arrDesc.top();
        mp[temp]++;
        arrDesc.pop();
        return temp;
    }
    
    void addBack(int num) {
        bool check = false;
        
        for(auto &data : mp){
            if(data.second > 0  && data.first == num) {
                check = true;
                mp[data.first]--;
                break;
            }
        }
        
        if(check){
            arrDesc.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */