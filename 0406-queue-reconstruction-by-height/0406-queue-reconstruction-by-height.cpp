class Solution {
public:
   static bool cmp(vector<int>&arr1,vector<int>&arr2){//O(n2)
        return (arr1[0]!=arr2[0])?arr1[0]>arr2[0]:arr1[1]<arr2[1];
    }       
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
   vector<vector<int>>res;// vector<vector<int>>res(people.size(),vector<int>());
        sort(people.begin(),people.end(),cmp);
        for(auto &it:people){
            res.insert(res.begin()+it[1],it);//res[res.begin()+it[1]]=it;
        }
        return res;
    }
    
};