class Solution {
public:
//     dp[i][j] contains the maximum number of lines we can draw by choosing the first i numbers from nums1 and the first j numbers from nums2. Our answer would be dp[n1][n2], 
// n1 is the length of nums1 and 
// n2 is the length of nums2. 
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
       int n1=nums1.size();
       int n2=nums2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else {
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
    return dp[n1][n2];}
};