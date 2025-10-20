/*

# Observation
⦁	Timestamp should given in asc order
⦁	We cant have a data that with same key and same timestamp
⦁	There is a case where we will have different key with the same timesamp
⦁	We need to create 2 functions, get and set

# HashMap + Vector + Binary search

# Simulation
-> set("foo", "bar", 1)

["foo"] -> [{bar, 1}]

-> set("foo", "rab", 2)

["foo"] -> [{bar, 1}, {rab, 2}]

-> set("foo", "bar", 3)

["foo"] -> [{bar, 1}, {rab, 2}, {bar, 3}]

-> get("foo", 3)
return : "bar"

-> get ("foo", 10)
return : "bar"

-> get("foo", 2)
return : "rab"

# Pseudocode
1.	Create a class Data
   - string value
   - int timestamp
2. Create a hashmap with key = string and value = vector<Data>
3. set functions
   - hashMap[key].push_back(new Data(key, value))
4. get functions
   - left = 0
   - right = hashTable[key].size()
   - result = ""
   - do binary search algorithm to find the data
   - return the result

Time Complexity : (N + logN)
set functions -> O(N)
N -> size of vector
get functions -> O(log N)

Memory Compelxity : (N * M)
N -> size of vector
M -> total key in the hashtable

*/

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