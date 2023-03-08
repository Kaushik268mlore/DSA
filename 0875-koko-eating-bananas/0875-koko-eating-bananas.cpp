class Solution {
public:
    /*
    int minEatingSpeed(vector<int>& piles, int H) { i loved this problem ,but leetcode is a scam bro..
        int l=1,r=1000000000;
        while(l<=r){
            int mid=(l+r)/2;
            int h=0;
            for(int i=0;i<piles.size();i++)
                h+= ceil(1.0 * piles[i]/mid);
            
            if(h>H)
                l=mid+1;
            else h=mid-1;
            
        }
        return l;
    }*/
    bool check(int mid, int H, vector<int>arr){
        long long tothrs=0;
        for(int i:arr){
            tothrs+=ceil(1.0*i/mid);
        }
        return tothrs>H;
    }
       int minEatingSpeed(vector<int>& piles, int H) {// a binary search problem again, similar to yesterday's
         
        int low = 1, high = 1000000000, k = 0;
        while (low <= high) {
            k = (low + high) / 2;
            if (check(k,H,piles))
                low = k + 1;
            else
                high = k - 1;
        }
        return low;
    }
    
};