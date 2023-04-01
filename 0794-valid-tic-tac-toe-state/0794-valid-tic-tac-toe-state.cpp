class Solution {
private:
//     bool winning(vector<string> &board, char c) {
//         for(int i = 0; i < 3; i++)
//             if(board[i][0] == c && board[i][1] == c && board[i][2] == c) return true;
//         for(int j = 0; j < 3; j++)
//             if(board[0][j] == c && board[1][j] == c && board[2][j] == c) return true;
//         if(board[0][0] == c && board[1][1] == c && board[2][2] == c) return true;
//         if(board[2][0] == c && board[1][1] == c && board[0][2] == c) return true;
//         return false;
//     }
//     int count(vector<string> &board, char c) {
//         int cnt = 0;
//         for(auto r : board)
//             for(auto val : r)
//                 cnt += (c == val);
//         return cnt;
//     }
    
// public:
//      bool validTicTacToe(vector<string>& board) {
//         int xs = count(board, 'X'), os = count(board, 'O');
//         return xs == os ? !winning(board, 'X') : xs == os + 1 ? !winning(board, 'O') : false;
//     }
    public:
    bool validTicTacToe(vector<string>& board){
        int cntX=0,cntO=0;
        for( string s:board){
            //if(s=="XXX"||s=="OOO")return true;
            for(char c:s){
                if(c=='X')cntX++;
                if(c=='O')cntO++;
            }
        }
        cout<<cntX<<" "<<cntO<<"\n";
        if(cntX==cntO){                     // when the count is equal, and if X wins then O can't play the next move to equalise the no.of moves 
            return !checkwinner(board,'X');
        }
        else {                              //when the count is not equal and in that case, we see if the there is a valid game , then it will have cntX==cntO+1 ,in that case we'll see if O is winning or not ,if it is winning, then it is impossible because O always equalises the no.of moves of X , and cntX ==cntY shd have been the case..
            if(cntX==cntO+1){
            return !checkwinner(board,'O');
            }
            else return false;
        }
        return false;
    }
    bool checkwinner(vector<string>&b,char c){
        for(int i=0;i<3;i++){
            cout<<"entered"<<"\n";
            if(b[i][0]==c&&b[i][1]==c&&b[i][2]==c)return true;
        }
        for(int i=0;i<3;i++){
            if(b[0][i]==c&&b[1][i]==c&&b[2][i]==c)return true;
        }
        if(b[0][0]==c&&b[1][1]==c&&b[2][2]==c)return true;
        if(b[2][0]==c&&b[1][1]==c&&b[0][2]==c)return true;
        return false;
    }
    
    
};