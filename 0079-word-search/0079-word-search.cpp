// class Solution {
// public:
//     bool dfs(int i,int j,int sz,vector<vector<char>>&vis,string w){
//         if(sz==w.size())return true;
//         if(i<0||i>=vis.size()||j<0||j>=vis[0].size()||vis[i][j]!=w[sz])return false;
//         vis[i][j]='0';
//         int dir[4][2]={
//                        {1,0},
//                        {0,1},
//                        {-1,0},
//                        {0,-1}
//                       };
//         bool res=false;
//         for(int i=0;i<4;i++){
//             int x=dir[i][0],y=dir[i][1];
//             res=res||dfs(i+x,j+y,sz+1,vis,w);
//         }
//         vis[i][j]=w[sz];
//         return res;
//     }
//     bool exist(vector<vector<char>>& board, string word) {
//         // return dfs(0,0,0,board,word);
//         for(int i=0;i<board.size();i++){
//             for(int j=0;j<board[i].size();j++){
//                 if(board[i][j]==word[0]&&dfs(i,j,0,board,word))return true;
//             }
//         }
//     return false;
//     }
// };
class Solution {
public:
    //pass board by reference
    bool DFS(vector<vector<char>>& board, string word, int i, int j, int n) {
		//check if all the alphabets in the word is checked
        if(n == word.size()) return true; 
        
		//check if i and j are out of bound or if the characters aren't equal
        if(i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[n]) return false;
        
		//mark as visited 
        board[i][j] = '0';
        
		//branch out in all 4 directions
        bool status = DFS(board, word, i + 1, j, n + 1) ||  //down
                        DFS(board, word, i, j + 1, n + 1) ||  //right
                        DFS(board, word, i - 1, j, n + 1) ||  //up
                        DFS(board, word, i, j - 1, n + 1);  //left
        
		//change the character back for other searches
        board[i][j] = word[n];
		
        return status;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(word == "") return false;
        
        for(int i = 0; i < board.size(); i++) 
            for(int j = 0; j < board[i].size(); j++) 
				//check if the characters are equal then call DFS
                if(board[i][j] == word[0] && DFS(board, word, i, j, 0))
                    return true;
        
        return false;
    }
};