class Solution {
public:
    string getHint(string s, string g) {
        int a=0,b=0;
        int arr[10]={0};
        int brr[10]={0};
        for(int i=0;i<s.size();i++){
            char c1=s[i];
            char c2=g[i];
            if(c1==c2)a++;
            else {
                arr[c1-'0']++;
                brr[c2-'0']++;
            }
        }
        for(int i=0;i<10;i++){
            b+=min(arr[i],brr[i]);
        }
        return to_string(a)+"A"+to_string(b)+"B";
    }
};