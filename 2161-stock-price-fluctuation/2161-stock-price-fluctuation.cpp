class Node{
public:
    int timestamp;
    int proses;
    int price;

    Node(int timestamp, int proses, int price) {
        this -> timestamp = timestamp;
        this -> proses = proses;
        this -> price = price;
    }
};

struct CompareDesc {
    bool operator()(Node& first, Node& second) {
        
        if (first.price == second.price) {
            // sort by proses desc
            return first.proses > second.proses;
        } else {
            // sort by price
            return first.price < second.price;
        }
    }   
};

struct CompareAsc {
    bool operator()(Node& first, Node& second) {
        
        if (first.price == second.price) {
            // sort by proses desc
            return first.proses < second.proses;
        } else {
            // sort by price
            return first.price > second.price;
        }
    }   
};

class StockPrice {
private:
    // Timestamp | total update proses
    unordered_map<int,int> bucket; 
    priority_queue<Node, vector<Node>, CompareDesc> pqMax;
    priority_queue<Node, vector<Node>, CompareAsc> pqMin;
    pair<int,int> latest = make_pair(INT_MIN, INT_MIN);
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        bucket[timestamp]++;
        pqMax.push({timestamp, bucket[timestamp], price});
        pqMin.push({timestamp, bucket[timestamp], price});

        if (timestamp >= latest.first) {
            latest = make_pair(timestamp, price);
        }
    }
    
    int current() {
       return latest.second; 
    }
    
    int maximum() {
        
        while (pqMax.size() > 0) {
            auto node = pqMax.top();
            // cout << node.timestamp << " " << node.proses << " " << node.price << endl;
            // compare the proses
            if (bucket[node.timestamp] == node.proses) {
                return node.price;
            }

            pqMax.pop();
        }

        return 0;
    }
    
    int minimum() {
        while (pqMin.size() > 0) {
            auto node = pqMin.top();

            // compare the proses
            if (bucket[node.timestamp] == node.proses) {
                return node.price;
            }

            pqMin.pop();
        }

        return 0;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */