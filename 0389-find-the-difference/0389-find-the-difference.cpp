class Solution {
public:
    char findTheDifference(string s, string t) {
        int S=0,T=0;
        for(char c:s){
            S+=(c-'a');
        }
        for(char c:t){
         T+=(c-'a');   
        }
        return 'a'+(T-S);
    }
};