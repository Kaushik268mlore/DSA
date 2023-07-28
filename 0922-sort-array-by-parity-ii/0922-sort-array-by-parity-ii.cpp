class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>par(2,vector<int>());
        for(int i=0;i<n;i++){
            int p=nums[i]&1;
            par[p].push_back(nums[i]);
        }
        vector<int>res(n);
        for(int i=0,cnt=0;i<n&&cnt<n/2;i+=2,cnt++){
            res[i]=par[0][cnt];
        }
        for(int i=1,cnt=0;i<n&&cnt<n/2;i+=2,cnt++){
            res[i]=par[1][cnt];
        }
    return res;
    }
};