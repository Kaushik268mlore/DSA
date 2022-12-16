class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
        int n=arr.size(),ans,diff=INT_MAX;//2 pointers
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
               int temp=arr[i]+arr[j]+arr[k];
                if(abs(temp-target)<diff){
                    ans=temp;
                    diff=abs(temp-target);
                }
                else if(temp>target)k--;
                else j++;
            }
        }
        return ans;
    }
};