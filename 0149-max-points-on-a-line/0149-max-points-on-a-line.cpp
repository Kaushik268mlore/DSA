class Solution {
public:
    int maxPoints(vector<vector<int>>&arr) {//this is actually kinda easy , all u need is to just think mathematically
        int n=arr.size(),res=2;
        if(n==1)return 1;
        for(int i=0;i<n;i++){
            unordered_map<double,int>map;
            for(int j=0;j<n;j++){
                if(j!=i){
                    map[atan2(arr[j][1]-arr[i][1],arr[j][0]-arr[i][0])]++;
                }
            }
             for(auto i:map){
                 res=max(i.second+1,res);//includes the point that we started off with(+1)
             }
        }
        return res;
    }
};