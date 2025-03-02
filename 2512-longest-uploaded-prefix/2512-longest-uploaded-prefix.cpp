class LUPrefix {
private:
    set<int> st;
    int max = 0;
public:

    LUPrefix(int n) {
        
    }
    
    void upload(int video) {
        st.insert(video);
        while (st.count(max + 1)) max++;
    }
    
    int longest() {
        return max;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */