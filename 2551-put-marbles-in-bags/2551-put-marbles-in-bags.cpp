class Solution {
public:
// //     [1,3,5,1]
// literally thought this one would be DP , but holyF this is greedy LOL.
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        vector<long long>pw(n-1);
        for(int i=0;i<n-1;i++){
            pw[i]=weights[i]+weights[i+1];
        }
        sort(pw.begin(),pw.end());
        long long res=0;
        for(int i=0;i<k-1;i++){
            res+=(pw[n-2-i]-pw[i]);
        }
    return res;}
};