class Solution {
public:
    //this one's a good simulation problem , I wonder  why there are so many Dislikes
    //anyways here is a O(n) solution .. it does look like O(n2) but it isnt.
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        string res="";
        int inc=(numRows-1)*2;
        for(int i=0;i<numRows;i++){
            for(int j=i;j<s.length();j+=inc){
                res+=(s[j]);
                if(i>0&&i<numRows-1&& j+inc-2*i < s.length())res+=s[j+inc-2*i];
            }
        }
    return res;}
};