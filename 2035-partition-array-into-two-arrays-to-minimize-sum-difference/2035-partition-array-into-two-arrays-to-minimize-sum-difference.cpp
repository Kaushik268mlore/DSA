class Solution {
public:
//     LOL,really thought that this would solve it, but lmao partitions arent the same as the subarrays...bruhhh
  //   int minimumDifference(vector<int>& nums) {
  //       int n=nums.size();
  //       vector<int>lsum(n);
  //       vector<int>rsum(n);
  //       for(int i=1;i<n;i++){
  //           if(i==1){lsum[i-1]=nums[0];continue;}
  //           lsum[i]=lsum[i-1]+nums[i];
  //       }
  //       for(int i=n-1;i>=0;i--){
  //           if(i==n-1){rsum[i]==nums[i];continue;}
  //           rsum[i]=rsum[i+1]+nums[i];
  //       }
  //       // for(int i:lsum)cout<<i<<" ";
  //       int res=INT_MAX;
  //       for(int i=0;i<n-1;i++){
  //           res=min(res,abs(rsum[i]-lsum[i+1]));
  //       }
  // return res;  }
    vector<vector<int>> findAllSubsetsSum(vector<int>& nums, int l, int r) {
    int totLengthOfSubarray = r - l + 1;
    vector<vector<int>> res(totLengthOfSubarray + 1);
    for (int i = 0; i < (1 << totLengthOfSubarray); i++) {
        int sum = 0, countOfChosenNos = 0;
        for (int j = 0; j < totLengthOfSubarray; j++) {
            if (i & (1 << j)) {
                sum += nums[l + j];
                countOfChosenNos++;
            }
        }
        res[countOfChosenNos].push_back(sum);
    }
    return res;
}

int minimumDifference(vector<int>& nums) {
    int totalSum = accumulate(begin(nums), end(nums), 0);
    int n = nums.size();

    auto left = findAllSubsetsSum(nums, 0, n / 2 - 1);
    auto right = findAllSubsetsSum(nums, n / 2, n - 1);
    int target = totalSum / 2, ans = INT_MAX;

    //we can take (0 to n/2) length numbers from left
    for (int i = 0; i <= n / 2; i++) {
        //now we take rest - (n/2-i) length from right, we sort it to binary search
        auto r = right[n / 2 - i];
        sort(begin(r), end(r));

        for (int curleftSum : left[i]) {
            int needSumFromRight = target - curleftSum;
            auto it = lower_bound(begin(r), end(r), needSumFromRight);
            if (it != end(r))
                ans = min(ans, abs(totalSum - 2 * (curleftSum + *it)));
        }
    }
    return ans;
}
};