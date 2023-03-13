class RandomizedSet {
public:
    //saw this in Peter Pan's interview with the NEETCODE long ago , i remembered the 
    RandomizedSet() {
        
    }
    unordered_map<int,int>m;
    vector<int>arr;
    
    bool insert(int val) {
        if(!m.count(val)){
            arr.push_back(val);
            m[val]=arr.size()-1;
        return true;
        }
        return false;
        
    }
    
    bool remove(int val) {
        if(m.find(val)!=m.end()){
            m[arr.back()]=m[val];//the index is updated initially
            swap(arr.back(),arr[m[val]]);//the element to be deleted is swapped 
            arr.pop_back();//then its popped and deleted from the array
            m.erase(val);//erase it fron the array.
            return true;
        }
        else return false;
    }
    
    int getRandom() {
        int n=m.size();
        return arr[rand()%n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */