class Solution {
public:
    int numberOfSubarrays(vector<int>& arr, int k) {//sliding window solution
        return atmost(arr,k)-atmost(arr,k-1);//this is done to access the no.of subsets that contain exactly k elements
        //it is done by subtracting at most k-1 subests from k subsets
    }
    int atmost(vector<int>&arr,int k){
        int n=arr.size(),l=0,cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i]&1){
                k--;
            }
            while(k<0){
                if(arr[l++]&1){
                    k++;
                }
            }
            cnt+=(i-l+1);
            
            
        }
    return cnt;
    }
};