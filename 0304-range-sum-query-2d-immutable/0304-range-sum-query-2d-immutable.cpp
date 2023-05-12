class NumMatrix {
public:
    // segment tree can be used to calculate the sum 
    // but using prefix sum would be great.
    bool check(int r,int c,int n,int m){
        return (r>=0&&r<n&&c>=0&&c<m);
    }
    vector<vector<int>>dp;
    int n,m;
    NumMatrix(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        dp=matrix;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(check(i-1,j,n,m))dp[i][j]+=dp[i-1][j];
                if(check(i,j-1,n,m))dp[i][j]+=dp[i][j-1];
                if(check(i-1,j-1,n,m))dp[i][j]-=dp[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // if(row1!=0||col1!=0)int sum=dp[row2][col2]-(check(row1-1,col1-1,)
        int sum=0;
        if(check(row2,col2,n,m))sum+=dp[row2][col2];
        if(check(row1-1,col2,n,m))sum-=dp[row1-1][col2];
        if(check(row2,col1-1,n,m))sum-=dp[row2][col1-1];
        if(check(row1-1,col1-1,n,m))sum+=dp[row1-1][col1-1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */