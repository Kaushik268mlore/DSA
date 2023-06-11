class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        if(!n||!m)return false;
        int i=m-1,j=0;
        while(j<n&&i>=0){
            if(matrix[j][i]==target)return true;
            if(matrix[j][i]>target)i--;
            else j++;
        }
    return false;}
};