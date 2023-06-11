class Solution {
public:
    // [[1,5,9],
    // [10,11,13],
    // [12,13,15]]
    
    // int kthSmallest(vector<vector<int>>& matrix, int k) {
    //  if(k==1)return matrix[0][0];
    //     int n=matrix.size();
    //     if(k==n*n)return matrix[n-1][n-1];
    //     int i=1;
    //     while(i*i<=k&&i<n){
    //         i++;
    //     }
    //     int diff=i*i-k;
    //     return matrix[i-1][i-diff-1];
    // } bc this was supposed to work and idk how this isnt working..lmao
// I could right a klogn heap solution, but that's easy and not challenging , hence I'll try to write a
    // binary search solution.
    int kthSmallest(vector<vector<int>>&mat,int k){
        int n=mat.size();
        if(k==1)return mat[0][0];
        if(k==n*n)return mat[n-1][n-1];
        int l=mat[0][0],r=mat[n-1][n-1];
        while(l<r){
            int mid=(l+r)>>1;
            int cnt=0;
            for(int i=0;i<n;i++){
                cnt+=(upper_bound(mat[i].begin(),mat[i].end(),mid)-mat[i].begin());
            }
            if(cnt<k)l=mid+1;
            else r=mid;
        }
    return l;}
};