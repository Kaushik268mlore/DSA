class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int l=0,h=n*m-1,mid;
        while(l<=h)
        {
            mid=l+(h-l)/2;
            int row=mid/m;
            int column=mid%m;
            if(matrix[row][column]==target) return true;
            else if(matrix[row][column]<target) l=mid+1;
            else h=mid-1;
        }
        return false;
    }
};