class Solution {
public:
    int longestSubarray(vector<int>& arr, int limit) {//very important type of problem
        int n=arr.size(),ans=0,l=0;
        multiset<int>set;
       for(int i=0;i<n;i++){
           set.insert(arr[i]);
           while(!set.empty()&&*set.rbegin()-*set.begin()>limit){
               set.erase(set.find(arr[l++]));
           }
           ans=max(ans,i-l+1);
       }
        
    return ans;}
};