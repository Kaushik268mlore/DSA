class Solution {
public:
    int balancedString(string s) {///very different approach keep a note of this..
        int n=s.length(),cnt=n,j=0;
        unordered_map<char,int>arr;
        for(int i =0;i<n;i++){
            arr[s[i]]++;
        }
        for(int i=0;i<n;i++){
          arr[s[i]]--;
            while(j<n and arr['Q']<=n/4 and arr['W']<=n/4 and arr['E']<=n/4 and arr['R']<=n/4){
                cnt=min(cnt,i-j+1);
                arr[s[j++]]+=1;
            }
        }
    return cnt;}
};