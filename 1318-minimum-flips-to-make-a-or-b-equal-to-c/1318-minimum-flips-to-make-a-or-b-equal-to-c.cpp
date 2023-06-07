class Solution {
public:
    int minFlips(int a, int b, int c) {
        if((a|b)==c)return 0;
        bitset<32>ar=a;
        // cout<<ar;
        bitset<32>br=b;
        bitset<32>cr=c;
        int cnt=0;
        for(int i=0;i<32;i++){
            if(cr[i]){
                if(!ar[i]&&!br[i])cnt++;
            }
            else{
                if(ar[i])cnt++;
                if(br[i])cnt++;
            }
        }
    return cnt;}
};