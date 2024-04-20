class SnapshotArray {
public:
    
    // pair<int,int> = pair<snap_id, value>
    vector<vector<pair<int,int>>> bucket;
    int id;
    
    SnapshotArray(int length) {
        bucket.resize(length);
        for(int i = 0; i < length; i++){
            bucket[i].push_back(make_pair(0,0));
        }
        id = 0;
    }
    
    void set(int index, int val) {
        bucket[index].push_back(make_pair(id, val));
    }
    
    int snap() {
        return id++;
    }
    
    int get(int index, int snap_id) {
        
        auto it = upper_bound(bucket[index].begin(), bucket[index].end(), make_pair(snap_id, INT_MAX));
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */