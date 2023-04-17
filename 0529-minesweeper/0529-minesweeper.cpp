class Solution {
public:
    // this one's a cool problem, and obviously just apply dfs/bfs
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        vector<vector<bool>>vis(board.size(),vector<bool>(board[0].size()));
        dfs(board,vis,click[0],click[1]);
        return board;
    }
    void dfs(vector<vector<char>>&board,vector<vector<bool>>&vis,int i,int j){
        if (min(i, j)<0||i>=board.size()||j>=board[0].size()||vis[i][j]) return;
        vis[i][j]=true;
        int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
        int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};
        if(board[i][j]=='M'){
            board[i][j]='X';
            return;
        }
        if(board[i][j]=='E'){
            int cnt=bombsnearme(board,i,j);
            if(cnt==0){
                board[i][j]='B';//blank square
                for(int k=0;k<8;k++){
                dfs(board,vis,i+dx[k],j+dy[k]);
                }
            }
            else {
                board[i][j]='0'+cnt;//numbered
                return;
            }
        }
    }
    int bombsnearme(vector<vector<char>>&board,int i,int j){
    int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
    int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};
    int cnt=0;
        for(int k=0;k<8;k++){
            int nx=dx[k]+i;
            int ny=dy[k]+j;
            if((nx>=0&&ny>=0&&nx<board.size()&&ny<board[0].size())&&board[nx][ny]=='M')cnt++;
        }
    return cnt;}
};