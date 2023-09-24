class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        perm(ans,nums,0);
        return ans;
    }
    void perm(vector<vector<int>>&ans,vector<int>arr,int i){
        if(i==arr.size()){//base case
            ans.emplace_back(arr);//store the result of the current possibility
        }
        for(int l=i;l<arr.size();l++){
            if(i!=l&&arr[i]==arr[l])continue;
            swap(arr[l],arr[i]);
            perm(ans,arr,i+1);//recursive case
        }
    }
};