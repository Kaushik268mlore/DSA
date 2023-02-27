#define MOD 1000000007;
class Solution {
public:
    
    int nthMagicalNumber(int n, int a, int b) {//IDK  WHY  IS THIS TAGGED HARD?
        //its kinda hard to figure out that the logic below
        long long l=min(a,b),h=n*l,lc=lcm(a,b),ans;
        auto check =[&](long long x){return ((x/a)+(x/b)-(x/lc));};//this check is important it calculates the total numbers that are either divisible by a or b;
        while(l<h){//then we binary search through it.
            long long mid=l+(h-l)/2;
            if(check(mid)<n)l=mid+1;
            else h= mid;
        }
        return l%MOD;
    }
   
};