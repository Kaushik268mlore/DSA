class SnapshotArray {
public:
    vector<int>arr;
    int id=0;
    map<int,map<int,int>>m;
    SnapshotArray(int length) {
        // arr.resize(length);
        for(int i=0;i<length;i++){
            map<int,int>map;
            map[0]=0;
            m[i]=map;
        }
    }
    // vector<vector<int>>m
    void set(int index, int val) {
        m[index][id]=val;
    }
    
    int snap() {
       return id++; 
    }
    
    int get(int index, int snap_id) {
        auto it=m[index].upper_bound(snap_id);
        it--;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */