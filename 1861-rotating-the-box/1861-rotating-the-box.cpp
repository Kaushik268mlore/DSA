class Solution {
public:
// cool problem, I did it the brute-force way
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size();
        int m=box[0].size();
        for(int i=0;i<n;i++){
            for(int j=m-1;j>=0;j--){
                if(box[i][j]=='#'){
                    int start=j+1;
                    while(start<m&&box[i][start]=='.')start++;
                    if(start<m&&box[i][start]=='.'){
                        box[i][j]='.';
                        box[i][start]='#';
                    }
                    else if(start-1<m&&box[i][start-1]=='.'){
                        box[i][j]='.';
                        box[i][start-1]='#';
                    }
                }
            }
        }
        vector<vector<char>>res(m,vector<char>(n));
        int ec=n-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res[j][ec]=box[i][j];
            }
            ec--;
        }
    return res;}
};