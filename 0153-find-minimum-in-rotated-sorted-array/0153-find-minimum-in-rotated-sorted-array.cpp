class Solution {
public:
    int findMin(vector<int>& arr) {
        int l=0,r=arr.size()-1;
        while(l<r){//this is used when we implicitly return outside the for loop,whereas l<=r is used when we return inside the loop
            int mid=l+(r-l)/2;
            if(arr[l]<arr[r]){
                return arr[l];
            }
            
           if(arr[mid]>=arr[l]){
                l=mid+1;
            }
            else {r=mid;}
        }
        return arr[l];
    }
};