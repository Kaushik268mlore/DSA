#define LL long long
class Solution {
public:
    
    int solve(string s){
        LL sum=0;
        int sign=1;
        int n=s.size();
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++){
            char c=s[i];
            if(isdigit(c)){
                LL num=0;
                while(i<n&&isdigit(s[i])){
                    num=((num*10)-'0'+s[i]);
                    i++;    
                }
                i--;
                sum+=(sign*num);
                sign=1;
            }
            else if(c=='('){
                st.push({sum,sign});// save previous state.
                sum=0;
                sign=1;
            }
            else if(c==')'){
                sum=(st.top().first)+(st.top().second*sum);
                // sum=0;
                // sign=1;
                st.pop();
            }
            else if(c=='-')sign*=-1;
        }
    return sum;
    }
    int calculate(string s) {
        
        return solve(s);
    }
};