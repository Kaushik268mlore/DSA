/*The sub trees left and right, should be in order but the trees in them selves can be put and any order
eg: [3,4,5,1,2] the subtrees are [4,5],[1,2]. These can be arranged as [4,1,5,2], [4,1,2,5], [1,4,5,2], [1,4,2,5], [1,2,4,5].
This essentially means we have to choose subTtree.size spaces from (leftSubTree+rightSubTree).size()
*/
static int MOD=1e9+7,MODINV=1e9+5;
static int combs[1001][1001]={0};
class Solution {
public:
    int powMod(int base,int exp)
    {
        long long temp=base,result=1;
        while(exp>0)
        {
            if(exp&1)
                result=(result*temp)%MOD;
            temp=(temp*temp)%MOD;
            exp>>=1;
        }
        return result;
    }
    int nCr(int n,int r)
    {
        if(combs[n][r]!=0)
            return combs[n][r];
        if(r>n/2)
            r=n-r;
        long long result=1;
        for(int i=1;i<=r;i++)
            result=(((result*(n-i+1))%MOD)*powMod(i,MODINV))%MOD;
        return result;
    }
    int dfs(vector<int>& nums)
    {
        if(nums.size()<=2)
            return 1;
        vector<int> leftTree,rightTree;
        for(int &i:nums)
            if(i>nums.front())
                rightTree.push_back(i);
            else if(i<nums.front())
                leftTree.push_back(i);
        long long leftRes=dfs(leftTree),rightRes=dfs(rightTree);
        return (((nCr(nums.size()-1,leftTree.size())*leftRes)%MOD)*rightRes)%MOD;
    }
    int numOfWays(vector<int>& nums) 
    {
        return dfs(nums)-1;
    }
};