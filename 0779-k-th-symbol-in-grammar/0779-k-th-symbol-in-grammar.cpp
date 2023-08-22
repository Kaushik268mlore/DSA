class Solution {
public:
//     void f(int n,string &s){
//         if(s.length()==pow(2,n-1))return;
        
//     }
//     }
   //  string complement(string s){   //BC memory limit exceeded
   //      for(int i=0;i<s.length();i++){
   //          if(s[i]=='0')s[i]='1';
   //          else s[i]='0';
   //      }
   // return s; }
   //  int kthGrammar(int n, int k) {
   //      string s="0";
   //      if(n==1)return 0;
   //      for(int i=0;i<n;i++){
   //          s+=complement(s);
   //      }
   //  return s[k-1]-'0';}
//     Number of bits in a row, Nb = pow(2, row_number-1)

// If K is less than Nb/2 (lies in 1st half), then we can check same bit in previous row as both will be same : [kthGrammar(N-1, K)]
// If K is more than Nb/2 (lies in 2nd half), then we can check (K-Nb/2)th bit (which will be in 1st half) and flip that.
// Example:
// 0110
// 0110 1001
// 5th bit = flip of 1st bit same row = flip of 1st bit in previous row. [!kthGrammar(N-1, K-pow(2, N-2));] (pow(2, N-2) is half of number bits in that row)
    int kthGrammar(int n,int k){
        if(n==1&&k==1)return 0;
        if(k<=pow(2,n-2)){
            return kthGrammar(n-1,k);
        }
        return !kthGrammar(n-1,k-pow(2,n-2));
    }
};