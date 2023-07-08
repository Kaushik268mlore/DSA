class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int,int>m;
        // for(int i=0;i<arr.size();i++)m[arr[i]]=i;
        for(int i=0;i<arr.size();i++){
            if(m.find(target-arr[i])!=m.end())return {i,m[target-arr[i]]};
            else m[arr[i]]=i;
        }
    return {};}
};