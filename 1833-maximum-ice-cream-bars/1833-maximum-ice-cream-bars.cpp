class Solution {
public:
    int maxIceCream(vector<int>& arr, int coins) {
        sort(arr.begin(),arr.end());
      //  bool buy=true;
        int cnt=0;
        for(int i=0;i<size(arr);i++){
            if(arr[i]<=coins){cnt++;coins-=arr[i];}
        }
        return cnt;}
};