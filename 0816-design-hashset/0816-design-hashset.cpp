class MyHashSet {
private:
    int getIndex(int key) {
        return key / 32;
    }

    int getKey(int key) {
        int res = key % 32;
        return 1 << res;
    }
public:
    int num[31251] = {0};

    MyHashSet() {

    }
    
    void add(int key) {
        int index = getIndex(key);
        key = getKey(key);

        // insert key to spesific index
        num[index] |= key;
    }
    
    void remove(int key) {
        // remove key from spesific index
        int index = getIndex(key);
        key = ~getKey(key);

        num[index] &= (key);
    }
    
    bool contains(int key) {
        int index = getIndex(key);
        key = getKey(key);

        return (num[index] & key) != 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */