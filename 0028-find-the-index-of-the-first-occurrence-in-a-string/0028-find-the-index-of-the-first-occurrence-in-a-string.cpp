class Solution {
public:
    // int strStr(string haystack, string needle) {
    //     return haystack.find(needle);//this is the easiest medium I've ever solved in my life
    // }
    // int strStr(string haystack, string needle){ // bruteforce/sliding window approach
    //     int n=haystack.length();
    //     int m=needle.length();
    //     for(int i=0;i<n-m+1;i++){
    //         for(int j=0;j<m;j++){
    //             if(needle[j]!=haystack[i+j])break;
    //             if(j==m-1)return i;
    //         }
    //     }
    // return -1;
    // }
        int strStr(string haystack, string needle) {// this is a double rolling hash algorithm aka KMP algorithm
        int m = haystack.size(), n = needle.size();
        if (!n) {
            return 0;
        }
        vector<int> lps = kmpProcess(needle);
        for (int i = 0, j = 0; i < m;) {
            if (haystack[i] == needle[j]) { 
                i++, j++;
            }
            if (j == n) {
                return i - j;
            }
            if (i < m && haystack[i] != needle[j]) {
                j ? j = lps[j - 1] : i++;
            }
        }
        return -1;
    }
private:
    vector<int> kmpProcess(string needle) {
        int n = needle.size();
        vector<int> lps(n, 0);
        for (int i = 1, len = 0; i < n;) {
            if (needle[i] == needle[len]) {
                lps[i++] = ++len;
            } else if (len) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
        return lps;
    }
};