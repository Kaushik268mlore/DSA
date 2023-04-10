class Solution {
public:
    int minTimeToType(string word) {
        int cnt=0;
        char init='a';
        for(char c:word){
            cnt+=min(abs(c-init),26-abs(c-init))+1;
            init=c;
        }
    return cnt;}
};