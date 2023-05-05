class Solution {
public:
    bool check(char c){return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');}
    // sliding window problem
    int maxVowels(string s, int k) {
    int res=0;
        int n=s.length();
            int temp=0;
        for(int i=0;i<n;i++){
               if(i>=k&&check(s[i-k]))--temp;
                if(check(s[i]))++temp;
            
            // cout<<temp<<"\n";
            if(temp==k)return k;
            res=max(res,temp);
            // if(temp)
        }
        // cout<<"endcase\n";
    return res;}
};