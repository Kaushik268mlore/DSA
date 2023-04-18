class Solution {
public:
    string mergeAlternately(string word1, string word2) {
      string res="";
        int n=word1.length(),m=word2.length();
        for(int i=0,j=0;i<n||j<m;i++,j++){
            // res+=(word1[i]+word2[i]);
            if(i<n)res+=word1[i];
            if(j<m)res+=word2[j];
        }
        return res;
    }
};