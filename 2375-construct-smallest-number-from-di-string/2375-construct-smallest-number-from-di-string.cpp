class Solution {
public:
    string smallestNumber(string pat) {
       int n=pat.length();
        // int maxx=min(n,9);
        int id=0;
        char minn='1';
        string res="1";
        for(int i=0;i<n;i++){
            char ch=pat[i];
            if(ch=='I'){
                res.push_back(++minn);
                id=res.size()-1;
            }
            else {
                res.push_back(++minn);
                for(int k=res.size()-1;k>id;k--){
                    swap(res[k],res[k-1]);
                }
            }
        }
    return res;}
};