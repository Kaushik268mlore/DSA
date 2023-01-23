class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        int e1=0,e2=0;
        int N=s.length();
        for(int i=0;i<N;i++)e1+=(s[i]-'0'),e2+=(target[i]-'0');
        cout<<e1<<" "<<e2<<"\n";
        return (e1>0&&e2>0||e1==0&&e2==0)?true:false;
    }
};