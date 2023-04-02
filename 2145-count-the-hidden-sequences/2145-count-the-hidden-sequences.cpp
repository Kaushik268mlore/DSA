class Solution {
public:
// cumulative min and max will provide us with the offsets
//lets assume we start calculating the sequence, considering first element to be 0.
//then we have to see if this fits inside the given range [lower,upper]
//we see if gap=upper-lower-(maxx-minn)+1 is >0
// if it is gap>0 ,then we can have gap number of sequences.
// in-fact this problem needs to think in a bit
//also I feel I should strengthen my prefix sum concepts.
long maxx,minn,prsum;
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
           maxx=0,minn=0,prsum=0;
        for(int i:differences){
            prsum+=i;
            maxx=min(maxx,prsum);
            minn=max(minn,prsum);
        }
        long ans=upper-lower+(maxx-minn)+1;
        if(ans<0)return 0;
        return ans;
    }
    
};