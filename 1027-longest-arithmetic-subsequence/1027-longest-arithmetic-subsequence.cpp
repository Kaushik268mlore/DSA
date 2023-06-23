class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        unordered_map<int,vector<int>>m;
        int n=nums.size(),ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int gap=nums[j]-nums[i];
                if(m.find(gap)==m.end()){
                    m[gap]=vector<int>(1001,1);
                }
                m[gap][i]=max(m[gap][i],m[gap][j]+1);
                ans=max(ans,m[gap][i]);
            }
        }
    return ans;}
};