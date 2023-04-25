class Solution {
public:
    void transpose(vector<vector<int>>&matrix){
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int temp=matrix[j][i];
                matrix[j][i]=matrix[i][j];
                matrix[i][j]=temp;
            }
        }
    }
    void reflect(vector<vector<int>>& matrix){
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n/2;j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[i][n-j-1];
                matrix[i][n-j-1]=temp;
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
                int iMin = 0; // top border
        int iMax = matrix.size()-1; // bottom border
        int jMin = 0; // left border
        int jMax = matrix.size()-1; // right border

        for(int z=0; iMin<iMax && jMin<jMax; z++){
            for(int i=iMin,j=jMin,l=iMax,k=jMax; i<iMax; i++,j++,k--,l--){
                swap(matrix[iMin][j],matrix[i][jMax]);
                swap(matrix[iMax][k],matrix[l][jMin]);
                swap(matrix[iMax][k],matrix[iMin][j]);
            }
            iMin++;
            jMin++;
            iMax--;
            jMax--;
        }
    }
    
};