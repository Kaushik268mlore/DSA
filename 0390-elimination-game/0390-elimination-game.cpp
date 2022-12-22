//nice and easy problem!

class Solution {
public:
    //1 2 3 4 5
    //2 4
    //2
/*    int lastRemaining(int n) {// ma dumb solution
        if(n==1){
            return 1;
        }
        vector<int>arr(n,1);
        for(int i=0;i<n/2;i++){
           if(i&1==0)for(int j=0;j<n&&arr[j]!=0;j+=2){
               arr[j]=0;
           }
            else {
                for(int j=n-1;j>=0 and arr[j]!=0;j-=2)arr[j]=0;
            }
        }
        int ans;
        for(int i=0;i<n;i++)if(arr[i]==1)ans=i;
        return abs(ans-1);
    }
*/
    int lastRemaining(int n) {//steo keeps getting divided every iteration
        int ans=1,step=1;
        bool dir=true;//if T -> else <-
        while(n>1){
            if(dir)ans+=step;
            else {ans+=n%2==0?0:step;}
            step*=2;
            n/=2;
            dir=!dir;
        }
        return ans;
    }
};