class Data {
private:
    string value;
    int timestamp;
public:
    Data(string value, int timestamp) {
        this -> value = value;
        this -> timestamp = timestamp;
    }

    string getValue() {
        return this -> value;
    }

    int getTimestamp() {
        return this -> timestamp;
    }
};

class TimeMap {
private:
    unordered_map<string,vector<Data>> hashMap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
       hashMap[key].push_back(Data(value, timestamp));
    }
    
    string get(string key, int timestamp) {
        int left = 0;
        int right = hashMap[key].size() - 1;
        string result = "";

        // do binary search to find the result
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (hashMap[key][mid].getTimestamp() <= timestamp) {
                result = hashMap[key][mid].getValue();
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */