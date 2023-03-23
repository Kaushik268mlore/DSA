class Solution {
public:
    //this is a pretty easy problem..just check if the rowss, colums, blocks have repetition of the numbers.
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>>r(9),co(9),b(9);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                int c=board[i][j]-'0';
                if(board[i][j]=='.')continue;
                if(r[i].count(c)||co[j].count(c)||b[(i/3)*3+j/3].count(c))return false;
                r[i].insert(c);
                co[j].insert(c);
                b[(i/3)*3+j/3].insert(c);
            }
        }
    return true;}
};