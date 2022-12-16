class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {// 2pointers solution
        vector<vector<int>>triplets;
        int n=arr.size();
        sort(arr.begin(),arr.end());//sorting the array
        if(n<3){return {};}//if the size is less than 3, a triplet cannot be formed
        if(arr[0]>0){return {};}//if there are no negative terms at all we cant find any triplets
        for(int i=0;i<n;i++){
           if(arr[i]>0){break;}//we only check for other 2  other terms corresponding to the values the arr[i]th value if its negative , because the array is sorted. 
           int j=i+1,k=n-1,sum=0;// assigning the other pointers and using the conditional window compression method 
           if(i>0&&arr[i]==arr[i-1])continue;// if there are same negative vakues, we have to use the most extremist value of all
           while(j<k){
               sum=arr[i]+arr[j]+arr[k];
               if(sum<0){//so if sum is negative ,then we need more positive values which means lower pointer has to be updated.
                   j++;
               }
               else if(sum>0){//whereas here all we need to do when the sum is positive is decrease the positive values
                   k--;
               }
               else{// in all the other cases we have to push it to the array
                   triplets.push_back({arr[i],arr[j],arr[k]});
                   int lo_low=arr[j],lo_high=arr[k];
                   while(j<k&&lo_low==arr[j])j++;// and meanwhile also make sure we maintain distinct array values
                   while(j<k&&lo_high==arr[k])k--;
               }
           }
       }
        return triplets;
    }
};