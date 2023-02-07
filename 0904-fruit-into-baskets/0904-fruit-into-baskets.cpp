class Solution {
public:
    int totalFruit(vector<int>& arr) {
        deque<int>typefreq;  
        int n =arr.size(),size=0,cnt=0,a=0,b=0;
        int res=INT_MIN,l=0,r=0;
       for(int i=0;i<n;i++){
         int curr=arr[i];
           if(curr==b){
            cnt++;
            size++;   
           }
           else if(curr==a){
             cnt++;
               size=1;
               a=b;
               b=curr;
               
           }
           else{
               cnt=size+1;
               size=1;
               a=b;
               b=curr;
               
            }
           res=max(cnt,res);
       }
        
    return res;}
};