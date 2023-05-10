class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>res(n,vector<int>(n,0));
        int sr=0,sc=0,er=n-1,ec=n-1;
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        int cnt=1;
        int x=0;
        while(cnt<=n*n){
            res[sr][sc]=cnt++;
            int r=(((sr+dx[x])%n)+n)%n;
            int c=(((sc+dy[x])%n)+n)%n;
            if(res[r][c]!=0)x=(x+1)%4;
            sr+=dx[x];
            sc+=dy[x];
        }
    return res;}
};