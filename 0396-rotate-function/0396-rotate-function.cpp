class Solution {
public:
    /* Explanation :

A = [4, 3, 2, 6]

All the positions when rotated can be represented using the array : [4, 3, 2, 6, 4, 3, 2, 6] that is array A repeated twice.


idx : 0 1 2 3 4 5 6 7
arr : 4 3 2 6 4 3 2 6

All rotations :

4 3 2 6 -> 0 to 3

3 2 6 4 -> 1 to 4

2 6 4 3 -> 2 to 5

6 4 3 2 -> 3 to 6

fn first calculates the answer for the first permutation which is [4, 3, 2, 6] = 25

Moving to next permutation which is [3, 2, 6, 4] we see we're removing (0*4) and adding (4*4) when sliding on the extended array.

But since our answer would now be having (1*3 + 2*2 + 3*6 + 4*4) which is just array_sum + (0*3 + 1*2 + 2*6 + 3*4) we would have to subtract the array_sum once at each iteration from our answer;

 long removed = (l-1) * A[l-1];
 long added = r * A[r%len];
            
 newfn = newfn - removed + added - sum; */
    /*int maxRotateFunction(vector<int>& nums) {
        int  n=size(nums),sum=0,fsum=0;
        for(int i=0;i<n;i++){
              fsum+=(i*nums[i]);
        }
        int len=1,r;
        int newsum=fsum;
        while(len<n){
            r=len+n-1;
            int rem=(len-1)*nums[len-1];
            int add=r*(nums[r%n]);
            newsum=newsum+add-rem-sum;
            newsum=max(fsum,newsum);
            len++;
        }
    return newsum;}*/
    long long int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            ans += i*nums[i];
        }
        int index=n-1;
        int res=ans;
        for(int k=1;k<n;k++){
            ans = ans - ((n-1)*nums[index]) + (sum-nums[index]);
            res=max(res,ans);
            index--;
        }
        return res;
    }
};