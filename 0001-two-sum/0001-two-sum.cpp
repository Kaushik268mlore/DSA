class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int,int>map;
        int n=arr.size();
        
        for(int i=0;;i++){
            auto id=map.find(target-arr[i]);
                if(id!=map.end())
                  return {i,id->second};
            map[arr[i]]=i;
        }
    }
};