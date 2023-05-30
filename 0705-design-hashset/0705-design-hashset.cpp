class MyHashSet {
public:
    const int mx=1e6;
    // vector<int>arr(mx+1);
    int arr[1000001]={0};
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(!arr[key])arr[key]++;
    }
    
    void remove(int key) {
        if(arr[key])--arr[key];
    }
    
    bool contains(int key) {
        return arr[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */