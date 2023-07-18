class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
     int n=arr.size(),ans=INT_MAX,len=INT_MAX;
    // multiset<int>s;
        // priority_queue<int,vector<int>,greater<int>>pq;
        vector<int>map(n,INT_MAX);
   int l=0,r=0,sz=0,sum=0;
        while(r<n){
            sum+=arr[r];
            while(sum>target){
            sum-=arr[l]; 
            l++;
            }
            if(sum==target){
              // pq.push(r-l+1);  
                int curr=r-l+1;
                if(l>1&&map[l-1]!=INT_MAX)ans=min(ans,curr+map[l-1]);
            len=min(len,curr);
            }
            map[r]=len;
            r++;
        }
        // int p=-1,q=-1;
        // if(pq.size()>1){
        //     p=pq.top();pq.pop();
        //     q=pq.top();pq.pop();
        // return p+q;
        // }
        
        // int res=p+q;
        
    return ans==INT_MAX?-1:ans;}
};