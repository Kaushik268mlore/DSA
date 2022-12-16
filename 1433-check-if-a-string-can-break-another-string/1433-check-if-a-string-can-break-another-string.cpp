class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
       sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        
        bool breakf1=1,breakf2=1;
        for(int i=0;i<s1.length();i++){
            if(s1[i]<s2[i])breakf1=0;
            if(s1[i]>s2[i])breakf2=0;
        }
    return (breakf1 ||breakf2);
    }
};