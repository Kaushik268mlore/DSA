class Solution {
public:
    double angleClock(int hour, int minutes) {
       double ans=abs((30*double(hour)-(5.5)*double(minutes)));
        return (min(ans,abs(360-ans)));
        
    }
};