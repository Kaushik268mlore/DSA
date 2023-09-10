class Solution {
public:
    int largestInteger(int num) {
       string s=to_string(num);
        int n=s.length();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(s[j]>s[i]&&(s[j]-'0')%2==(s[i]-'0')%2)swap(s[j],s[i]);
            }
        }
    return stoi(s);}
};