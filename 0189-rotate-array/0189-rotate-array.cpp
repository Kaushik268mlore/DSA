class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n= arr.size();
        if(k<0){return;}
        if(k>=n){k%=n;}
        vector <int>v(arr);
        for(int i=0;i<k;i++){
           arr[i]=arr[n-k+i];
        }
        for(int i=k;i<n;i++){
            arr[i]=v[i-k]; 
        }
    }
};