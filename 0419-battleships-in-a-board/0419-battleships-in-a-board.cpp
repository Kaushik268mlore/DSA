class Solution {
public:
    void dfs(vector<vector<char>>&board , int i,int j){//this is a standard DFS question,but i might need more practice, this surprisingly took long time to solve.
        int n=board.size(),m=board[0].size();
        board[i][j]='.';
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        for(int k=0;k<4;k++){
            int X=i+dx[k];
            int Y=j+dy[k];
            if(X>=0&&Y>=0&&X<n&&Y<m&&board[X][Y]=='X'){
                dfs(board,X,Y);
            }
        }
        }
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X'){
                    ans++;
                    cout<<ans<<" "<<i<<" "<<j<<endl;
                    dfs(board,i,j);
                }
            }
        }
    return ans;}
};