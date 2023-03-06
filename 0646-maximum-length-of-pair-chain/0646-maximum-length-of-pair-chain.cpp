class Solution {
public:
    int findLongestChain(vector<vector<int>>& arr) {//greedy solution
        sort(arr.begin(),arr.end(),[&](vector<int>a,vector<int>b){
            return a[1]<b[1];
        });
        int cnt=0,prev=-1e6;
        //vector<vector<int>>res;
        //for(auto i:arr){for(auto j:i){cout<<j<<" ";}cout<<"\n";}
        for(int i=0;i<arr.size();i++){
        if(prev<arr[i][0])prev=arr[i][1],cnt++;
        }
        return cnt;
}
};