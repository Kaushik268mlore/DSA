class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int res=0;
        for(int i=1;i<size(arr)-1;i++){
            if(arr[i-1]<arr[i]&&arr[i+1]<arr[i]){
                int l=i,r=i;
                while(l>0&&arr[l]>arr[l-1])l--;
                while(r<size(arr)-1&&arr[r]>arr[r+1])r++;
                res=max(res,r-l+1);
            }
        }
        return res;
    }
};