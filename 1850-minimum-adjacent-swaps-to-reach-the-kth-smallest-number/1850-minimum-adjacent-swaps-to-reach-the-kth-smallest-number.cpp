class Solution {
public:
    int getMinSwaps(string num, int k) {
        string src=num;
        int n=num.length(),cnt=0;
        while(k--)next_permutation(num.begin(),num.end());
        for(int i=n-1;i>=0;i--){
            int j=i;
            while(src[j]!=num[i])j--;
            for(int l=j;l<i;l++){
                swap(src[l],src[l+1]);
                cnt++;
            }
        }
    return cnt;
    }
};