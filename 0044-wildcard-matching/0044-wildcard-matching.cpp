class Solution {
public:
    //I really don't see the need to implement a DP solution , instead in a real-time scenario I'd probably code an iterative one instead
//         bool helper(const string &s, const string &p, int si, int pi, int &recLevel)
//     {
//         int sSize = s.size(), pSize = p.size(), i, curLevel = recLevel;
//         bool first=true;
//         while(si<sSize && (p[pi]==s[si] || p[pi]=='?')) {++pi; ++si;} //match as many as possible
//         if(pi == pSize) return si == sSize; // if p reaches the end, return
//         if(p[pi]=='*')
//         { // if a star is met
//             while(p[++pi]=='*'); //skip all the following stars
//             if(pi>=pSize) return true; // if the rest of p are all star, return true
//             for(i=si; i<sSize; ++i)
//             {   // then do recursion
//                 if(p[pi]!= '?' && p[pi]!=s[i]) continue;
//                 if(first) {++recLevel; first = false;}
//                 if(helper(s, p, i, pi, recLevel)) return true;
//                 if(recLevel>curLevel+1) return false; // if the currently processed star is not the last one, return
//             }
//         }
//         return false;
//     }
// public:
//     bool isMatch(string s, string p) {
//         int recLevel = 0;
//         return helper(s, p, 0, 0, recLevel);
//     }
    // above is a DP solution for reference
    //below is a greedy one , i'll definitely have to come to this one for sure.
    bool isMatch(string s, string p) {
        int iretpoint=-1, jretpoint=-1;
        int j = 0;
        for(int i =0; i<s.size(); ){
            if(j<p.size() && p[j]==s[i]||p[j]=='?'){
                i++;
                j++;
            }
            else if (j<p.size() && p[j]=='*'){
                iretpoint = i;
                jretpoint = j;
                j++;
            }
            else if (iretpoint!=-1){
                iretpoint++;
                i = iretpoint;
                j = jretpoint+1;
            }
            else
                return false;
        }
        return p.substr(j)==string(p.size()-j,'*');
    }
};