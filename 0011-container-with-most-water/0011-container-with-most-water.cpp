class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n=arr.size(),l=0,r=n-1,area=0,ans=0;//very important question
        while(l<r){
            int len=min(arr[l],arr[r]);
             area=max(len*(r-l),area);
            while(arr[r]<=len&&l<r)r--;
            while(arr[l]<=len&&l<r)l++;
        }
        return area;
    }
};