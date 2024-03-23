class PhoneDirectory {
public:
    
    vector<int> buckets;

    PhoneDirectory(int maxNumbers) {
        for(int i = 0; i < maxNumbers; i++){
            buckets.push_back(0);
        }
    }
    
    int get() {
        
        for(int i = 0; i < buckets.size(); i++){
            if(buckets[i] == 0){
                buckets[i] = 1;
                return i;
            }
        }
        
        return -1;
    }
    
    bool check(int number) {
        return buckets[number] == 1 ? false : true;
    }
    
    void release(int number) {
        buckets[number] = 0;
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */