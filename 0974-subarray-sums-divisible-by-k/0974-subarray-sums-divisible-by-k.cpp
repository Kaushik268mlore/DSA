class Solution {
public:
//     int subarraysDivByK(vector<int>& nums, int k) { //will give u tle
     
//         int prefixsum,count ;
//         count=0;
        
//         for(int i=0;i<nums.size();i++)
//         {
//             prefixsum = 0;
//             for(int j=i;j<nums.size();j++)
//             {
//                 prefixsum+=nums[j];
//                 if(prefixsum % k==0)
//                     count++;
//             }
//         }
        
//         return count;
//     }
//     // how the hell did i miss this? too good observational problem.
//     If a subarray is divisible by K, it has to be a multiple of K

// a-b=n*k, a = running total, b = any previous subarray sum, same as original prefix sum problems.

// We want to solve for b, so using basic algebra, b=a-n*k

// We don't know what n is, so we can get rid of n by modding every element by k
// (b%k) = (a%k) - (n*k)%k

// since n*k is a multiple of k and k goes into it evenly, the result of the (n *k)%k will be 0

// therefore
// b%k = a%k

// is the same as the formula we defined earlier, a-b=n*k

// where b = running total, a = any previous subarray sum

// So we just have to see if running total mod k is equal to any previous running total mod k
    int subarraysDivByK(vector<int>& nums, int k){
        unordered_map<int,int>m;
        int psum=0,res=0;
        m[0]=1;// so that if there is a %k=0 thing it gets included.
        for(int i=0;i<nums.size();i++){
            psum=(psum+nums[i]%k+k)%k;
            res+=m[psum];   
            m[psum]++;
        }
    return res;
    }
};