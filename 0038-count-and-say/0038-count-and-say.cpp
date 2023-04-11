class Solution {
public:
    //a good problem tbh.
    //an amazing simulation problem.
    string rec(int n){
        if(!n)return "";
        //if(n==1)return "1";
        string res="1";
//         for(int i=0;i<n;i++){
//             int cnt=1;
//             for(int i=0;i<res.size();i++){
                    
//             }
//         }
        while(--n){
            string cur="";
            for(int i=0;i<res.size();i++){
                 int cnt=1;
                while(i<res.size()-1&&res[i]==res[i+1])cnt++,i++;
                cur+=to_string(cnt)+res[i];
            }
            // --n;
            res=cur;
        }
    return res;
    }
    string countAndSay(int n) {
        return rec(n);
    }
};