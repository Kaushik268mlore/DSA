class Solution {
public:
    int findRadius(vector<int>& h, vector<int>& t) {
       sort(h.begin(),h.end());
       sort(t.begin(),t.end());
       vector<int>res(h.size(),INT_MAX);
        for(int i=0,j=0;i<h.size()&&j<t.size();){
            if(h[i]<=t[j]){
                res[i]=t[j]-h[i];
                i++;
            }
            else j++;
        }
        for(int i=h.size()-1,j=t.size()-1;i>=0&&j>=0;){
            if(h[i]>=t[j]){res[i]=min(res[i],h[i]-t[j]);i--;}
            else j--;
        }
    return *max_element(res.begin(),res.end());}
};