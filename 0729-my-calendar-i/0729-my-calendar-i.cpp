class MyCalendar {
public:

    vector<pair<int,int>> arr;

    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(int i = 0; i < arr.size(); i++){
            int first = arr[i].first;
            int second = arr[i].second;

            if(start < second && end > second){
                return false;
            }else if(start < first && end > first){
                return false;
            }else if(start < first && end > second){
                return false;
            }else if(start >= first && end <= second){
                return false;
            }
        }

        arr.push_back({start,end});

        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */