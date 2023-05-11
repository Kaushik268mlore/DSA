class Solution {
public:
//     i have a solution that can solve the problem with a copy of the matrix
//     also the initial doubt is to decide on which ones to consider  first 
//     but then I could make it for a matrix, row by row and then undo it for the next row.
    int count(vector<vector<int>>&board,int i,int j,int n,int m){
        int cnt=0;
        int dx[]={-1,-1,0,1,1,1,0,-1};
        int dy[]={0,1,1,1,0,-1,-1,-1};
        for(int k=0;k<8;k++){
            int r=i+dx[k];
            int c=j+dy[k];
            if(check(r,c,n,m,board))++cnt;
        }
        return cnt;
    }
    bool check(int i,int j,int n,int m,vector<vector<int>>arr){
        return (i>=0&&i<n&&j>=0&&j<m&&arr[i][j]==1);
    }
    void gameOfLife(vector<vector<int>>&board) {
        vector<vector<int>>cp=board;
        int n=board.size(),m=board[0].size();
        if(cp==board)cout<<"YES\n";
        for(int i=0;i<n;i++){
            // vector<int>d=board[i];
            for(int j=0;j<m;j++){
                int cnt=count(cp,i,j,n,m);
                cout<<cnt<<"\n";
                if(cnt<2&&cp[i][j])board[i][j]=0;
                else if((cnt==2||cnt==3)&&cp[i][j])continue;
                else if(cnt>3&&cp[i][j])board[i][j]=0;
                else if(cnt==3&&!cp[i][j])board[i][j]=1;
            }
        }
    }
};