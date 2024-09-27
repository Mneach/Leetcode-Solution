class MyCalendarTwo {
public:

    map<int, int> bookings;

    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        
        // need to mark the start and end, so we can get that [start, end] is in 1 interval
        // mark start with increment by 1
        bookings[start]++;
        
        // mark end with decrementt by 1
        bookings[end]--;

        int count = 0;

        // looping for every data in map
        for(auto booking : bookings){
            count += booking.second;

            // check triple booking
            if(count > 2){
                // revert the map mark
                bookings[start]--;
                bookings[end]++;
                return false;
            }
        }

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */