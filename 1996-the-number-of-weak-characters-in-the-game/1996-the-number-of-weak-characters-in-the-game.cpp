class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
       sort(properties.begin(),properties.end(),[] (vector<int>& a,vector<int>& b){
           if(a[0]==b[0])return a[1]>b[1];
           return a[0]<b[0];
       });
        int ans=0,var=INT_MIN;
        for(int i=properties.size()-1;i>=0;i--){
            if(properties[i][1]<var)ans++;
            var=max(properties[i][1],var);
        }
    return ans;}
};
/*what were doing here is that we should sort the first parameter and then check for the no.of second parameter greater than the recent answer.*/