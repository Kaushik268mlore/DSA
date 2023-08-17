class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort (g.begin(),g.end());
        sort(s.begin(),s.end());
        int n=size(g),m=size(s),i=0,j=0,res=0;
        while(i<n and j<m){
            if(g[i]<=s[j]){
                res++;
                i++;
                j++;
            }
            else j++;    
        }
        return res;}
};