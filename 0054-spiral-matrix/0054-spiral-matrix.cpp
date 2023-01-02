class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int tot=m*n;
        int cnt=0;
        vector<int>arr;
        int sr=0,sc=0,er=n-1,ec=m-1;
        while(cnt<tot){
            for(int i=sc;i<=ec&&cnt<tot;i++){
                arr.push_back(matrix[sr][i]);cnt++;
            }
            sr++;
            for(int i=sr;i<=er&&cnt<tot;i++){
                arr.push_back(matrix[i][ec]);cnt++;
            } 
            ec--;
            for(int i=ec;i>=sc&&cnt<tot;i--){
                arr.push_back(matrix[er][i]);cnt++;
            }
            er--;
            for(int i=er;i>=sr&&cnt<tot;i--){
                arr.push_back(matrix[i][sc]);cnt++;
            }
            sc++;
        }
    return arr;}
};