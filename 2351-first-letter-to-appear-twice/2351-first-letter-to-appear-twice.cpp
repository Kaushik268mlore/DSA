class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int>frq(27,0);
        char ret;
        for(char c:s){
            if(!frq[c-'a'])frq[c-'a']++;
            else{ ret= c;break;}
        }
    return ret;}
};