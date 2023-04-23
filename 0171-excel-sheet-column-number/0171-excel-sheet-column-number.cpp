#define LL long long
class Solution {
public:
    int titleToNumber(string sheet) {
       int n=sheet.length();
        LL cnt=0;
        // for(int i=0;i<n;i++){
        //     cnt+=pow(26,n-i)*(sheet[i]-'A');
        // }
        LL mul=1;
        for(int i=n-1;i>=0;i--){
            cnt+=mul*(sheet[i]-'A'+1);
            mul*=26;
        }
    return cnt;
    }
};