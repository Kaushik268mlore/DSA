class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {//the trick is in identifying the the limits of l and r
       int l=1,r=0,mid=0;
        for(int x:weights){
            l=max(x,l);
            r+=x;
        }
        
        while(l<r){
            int mid=l+(r-l)/2;
            if(countdays(weights,mid)<=D)r=mid;
            else l=mid+1;
        }
        return l;
    }
        int countdays(vector<int>&arr,int totalcap){
            int res=1,currcap=0;
            for(int x:arr){
                currcap+=x;
                if(currcap>totalcap)currcap=x,res+=1;
            }
            return res;
        }
};