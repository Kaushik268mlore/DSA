class Solution {
public:
   vector<vector<int>> fourSum(vector<int>& nums, int target) {//we'll be using a generaliseed solution for as k-sum
      sort(begin(nums),end(nums));
        return ksum(nums,0,4,target);
     }
    
    vector<vector<int>> ksum(vector <int>nums,int start,int k,long long target){
        vector<vector<int>>res;
        if(start== nums.size()){
            return res;
        }
        int avg=target/k;
        if(nums[start]>avg||avg>nums.back()){
            return res;
        }
        if(k==2)return twosum(nums,target,start);
        for(int i=start;i<nums.size();i++){
            if(i==start||nums[i-1]!=nums[i]){
                for(vector<int>subset:ksum(nums,i+1,k-1,static_cast<long>(target)-nums[i])){
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()),begin(subset),end(subset));
                }
            }
        }
        return res;
    }
    vector<vector<int>>twosum (vector<int>&nums,long long target,int start){
        vector<vector<int>>res;
        int n=nums.size();
        unordered_set<long long>s;
        for(int i=start;i<n;i++){
            if(res.empty()||res.back()[1]!=nums[i]){
                if(s.count(target-nums[i])){
                    res.push_back({int(target-nums[i]),nums[i]});
                }
            }
            s.insert(nums[i]);
        }
        return res;
    }
    /*
    vector<vector<int>> fourSum(vector<int>& arr, int target){//
        vector<vector<int>>res;
        int n=arr.size();
        if(n<4)return res;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-3;i++){
            if(i>0 and arr[i]==arr[i-1])continue;
            if(arr[i]+arr[i+1]+arr[i+2]+arr[i+3]>target)break;
            if(arr[i]+arr[n-3]+arr[n-2]+arr[n-1]<target)continue;
            for(int j=i+1;j<n-2;j++){
                if(j>i+1&&arr[j]==arr[j-1])continue;
                if(arr[i]+arr[j]+arr[j+2]+arr[j+1]>target)break;
                if(arr[i]+arr[j]+arr[n-2]+arr[n-1]<target)continue;
                int l=j+1,r=n-1;
                while(l<r){
                    long long sum=arr[i]+arr[j]+arr[l]+arr[r];
                    if(sum>target)r--;
                    else if(sum<target)l++;
                    else {
                        res.push_back(vector<int>{arr[i],arr[j],arr[l],arr[r]});
                        do{l++;}while(arr[l]==arr[l-1]&&l<r);
                        do{r--;}while(arr[r]==arr[r+1]&&l<r);
                    }
                }
            }
        }
        
        return res;
    }*/
   
};