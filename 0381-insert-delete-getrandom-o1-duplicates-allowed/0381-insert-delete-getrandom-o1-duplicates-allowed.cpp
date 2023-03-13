class RandomizedCollection {
public:
//     RandomizedCollection() {
        
//     }
//     unordered_map<int,unordered_set<int>>m;
//     vector<int>arr;
//     bool insert(int val) { 
//         arr.push_back(val);
//         m[val].insert(arr.size()-1);
//         cout<<m[val].size()<<endl;
//         return m[val].size()==1;
//     }
    
//     bool remove(int val) {
//         if(m[val].size()==0)return false;
//         auto i=*m[val].begin();
//         m[val].erase(i);
//         swap(arr.back(),arr[i]);
//         m[arr.back()].insert(i);
//         m[val].erase(size(arr)-1);
//         arr.pop_back();
//         return true;
//     }
    
//     int getRandom() {
//         return arr[rand()%arr.size()];
//     }
    
    //crazy and hard problem , some thought has to be put inorder to solve this one.
    
    vector<int> arr;
    unordered_map<int, unordered_set<int>> map; //val: {index in arr}
    
    RandomizedCollection() {}
    
    bool insert(int val) {
        arr.push_back(val);
        map[val].insert(arr.size()-1);
        return map[val].size() <= 1;
    }
    
    bool remove(int val) {
        if(map[val].size()==0) return false;
        int ind= *map[val].begin();
        map[val].erase(ind);
        
        int num= arr.back();
        swap(arr[ind], arr[arr.size()-1]);
        map[num].insert(ind);
        map[num].erase(arr.size()-1);
        arr.pop_back();
        return true;
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */