class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        perm(ans,nums,0);
        return ans;
    }
    void perm(vector<vector<int>>&ans,vector<int>&arr,int i){
        if(i>=arr.size()){//base case
            ans.push_back(arr);//store the result of the current possibility
            return;
        }
        for(int l=i;l<arr.size();l++){
            swap(arr[l],arr[i]);
            perm(ans,arr,i+1);//recursive case
            swap(arr[l],arr[i]);//backtrack
        }
    return;
    }
};