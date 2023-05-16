#define ll long long 
class Solution {
public:
//     vector<LL>res;
//     int med;
//     LL rec(vector<int>&arr,vector<int>&c,int ind,int cost,int n){
//         if(ind>=n)res.push_back(cost);
//         // if(op)
//         if()
//     }
//     we assume the curve of the total cost to be a convex curve, which tells us that , there is an inflexion point where there definitely is the solution point or the ideal mid value
//     I'm shocked such cool problem exists..
   ll paisa(ll m,vector<int> &nums,vector<int> &cost){
        ll kitna=0,n=nums.size();
        for(int i=0;i<n;i++){
            kitna+=(ll)(cost[i]*(abs(nums[i]-m)));
        }
        return kitna;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll l=*min_element(nums.begin(),nums.end());
        ll h=*max_element(nums.begin(),nums.end());
        while(l<h){
            ll mid=(l+h)/2;
            ll a=paisa(mid,nums,cost);
            ll b=paisa(mid+1,nums,cost);
            if(a>b){
                l=mid+1;
            }
            else{
                h=mid;
            }
        }
        return paisa(l,nums,cost);
    }
    
};