class Solution {
public:
    // a really good problem , we had this in out college labs..lol
    vector<vector<int>> generate(int numRows) {
     int cnt=numRows;
        vector<vector<int>>res(cnt);
     for(int i=0;i<cnt;i++){
             res[i].resize(i+1,1);
             for(int j=1;j<i;j++){
                 res[i][j]=res[i-1][j]+res[i-1][j-1];
             
         }
     }
    return res;}
};