class Solution {
public:
    int reachNumber(int target) {
        int delta=0;
        int cnt=0;
        target=abs(target);
        while(target>0){
            delta=target-(++cnt);
            target-=cnt;
        }
        if(delta&1){cnt=cnt+1+cnt%2;return cnt;}
        return cnt;
        
    }
};