class Solution {
public:
    int minAddToMakeValid(string s) {//this wasn't supposed to be medium and maybe there could be other folllow ups of this problem by introducing other symbols.
       int res=0,balance=0;
        for(char c:s){
           balance+=(c=='(')?1:-1;
            if(balance==-1)res++,balance++;
       } 
    return abs(res)+abs(balance);}
};