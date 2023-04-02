class Solution {
public:
    // int countNegatives(vector<vector<int>>& grid) { //this is very traditional O(n2)
    //     int cnt=0;
    //     for(int i=0;i<grid.size();i++){
    //         for(int j=0;j<grid[0].size();j++){
    //             if(grid[i][j]<0)cnt++;
    //         }
    //     }
    // return cnt;}
    //now we'll use the property of sortedness
    /*
    4,3,2,-1
    3,2,1,-1
    1,1,-1,-2
    -1,-1,-2,-3 we can traverse from top right to bottom left this would at max be O(m+n)
    */
    int countNegatives(vector<vector<int>>& grid){
        int n=grid.size(),m=grid[0].size(),cnt=0;
        int r=0,c=m-1;
        while(r<n){
            while(c>=0&&grid[r][c]<0){c--;cnt++;}
            c=m-1;r++;
        }
    return cnt;}
};