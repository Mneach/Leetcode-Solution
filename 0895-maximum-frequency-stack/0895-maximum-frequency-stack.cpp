class Freq{
public:
    int number;
    int freqNumber;
    int insertNumber;
    
    
    bool operator<(const Freq& other) const {
        if (freqNumber != other.freqNumber)
            return freqNumber < other.freqNumber;

        return insertNumber < other.insertNumber;
    }
    
};

class FreqStack {
public:
    
    priority_queue<Freq> pq;
    unordered_map<int,int> ump;
    int insertNumber = 0;
    
    FreqStack() {
        
    }
    
    void push(int val) {
        ump[val]++;
        insertNumber++;
        
        pq.push({val, ump[val], insertNumber});
        
        
    }
    
    int pop() {
        Freq res = pq.top();
        ump[res.number]--;
        
        pq.pop();
        
        
        return res.number;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */