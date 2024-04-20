class TimeMap {
private:
    unordered_map<string,vector<pair<int,string>>> ump;
public: 
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        ump[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // vector<pair<int,string>> current = ump[key];
        
        int left = 0;
        int right = ump[key].size() - 1;
        int answerIndex = -1;
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            
            if(ump[key][mid].first <= timestamp){
                answerIndex = max(mid, answerIndex);
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        // cout << answerIndex << " " << current[answerIndex].first << " " << current[answerIndex].second << endl;
        
        if(answerIndex == -1){
            return "";
        }else{
            return ump[key][answerIndex].second;
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */