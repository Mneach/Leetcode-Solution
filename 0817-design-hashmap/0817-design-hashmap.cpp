class MyHashMap {
public:
    int arr[1000001];
    
    MyHashMap() {
        for(int i = 0; i < 1000001; i++){
            arr[i] = -1;
        }
    }
    
    void put(int key, int value) {
       arr[key] = value; 
    }
    
    int get(int key) {
        if(arr[key] != -1) return arr[key];
        else return -1;
    }
    
    void remove(int key) {
        arr[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */