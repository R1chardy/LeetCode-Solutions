class SnapshotArray {
public:
    vector<map<int,int>> v;   //index is position, map is history of changes
    int id;
    SnapshotArray(int length) {
        id = 0;
        v.resize(length);
        for(auto& x : v){
            x[0] = 0;
        }
    }
    
    void set(int index, int val) {
        v[index][id] = val;
    }
    
    int snap() {
        return id++;
    }
    
    int get(int index, int snap_id) {
        if(v[index].find(snap_id) != v[index].end()){
            return v[index][snap_id];
        }
        auto result = --v[index].lower_bound(snap_id);
        return result->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */