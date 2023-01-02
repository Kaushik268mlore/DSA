class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.size(),cnt=0;
        for(int i=0;i<n;i++){
                if('Z'-word[i]>=0)cnt++;
        }
        return (cnt==0||cnt==n||(cnt==1&&'Z'-word[0]>=0));
    }
};