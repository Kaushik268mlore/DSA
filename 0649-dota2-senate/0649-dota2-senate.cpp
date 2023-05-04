class Solution {
public:
    // this problem is too good
    string predictPartyVictory(string senate) {
        queue<int>r,d;
        int n=senate.size();
        for(int i=0;i<n;i++){
            char c=senate[i];
            if(c=='R')r.push(i);
            if(c=='D')d.push(i);
        }
        while(!r.empty()&&!d.empty()){
            int rid=r.front(),did=d.front();
            r.pop();d.pop();
            if(rid<did){
                r.push(rid+n);
            }
            else d.push(did+n);
        }
    return (r.size()>d.size())?"Radiant":"Dire";}
};