class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream iss(s);
        string word;
        int ans=0;
        while(iss>>word){
            ans=word.length();
        }
    return ans;}
};