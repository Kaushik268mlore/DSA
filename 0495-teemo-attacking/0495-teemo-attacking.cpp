class Solution {
public:
    int findPoisonedDuration(vector<int>& t, int d) {
        // int d=duration;
        int n=t.size();
        if(n==0)return 0;
        int cnt=0;
        for(int i=0;i<n-1;i++){
            cnt+=min(t[i+1]-t[i],d);
        }
    return cnt+d;}//+d to account the last call
};