class Solution {
public:
    /*int lengthOfLongestSubstring(string s) {
       int ans=0,l=0,r=0;//sliding window approacch
        vector<int>store(256,0);
        while(r<s.length()){
            store[s[r]]++;
            while(store[s[r]]>1){
                store[s[l]]--;//erases the occurences of letters in the current window 
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
    return ans;}*/
    int lengthOfLongestSubstring(string s){
        int n=s.length(),i=0,j=0,ans=0;
        if(n==0)return 0;
        else if(n==1)return 1;
        unordered_map<int,int>map;
        while(i<n && j<n){
            if(map.find(s[i])!=map.end() and map[s[i]]>=j){
                j=map[s[i]]+1;
            }
            map[s[i]]=i;
            i++;
            ans=max(ans,i-j+1);
            
        }
        return --ans;
    }
};