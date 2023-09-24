class Solution {
public:
    bool poss(string s, int n, int cnt){
        if(s.size()==0){
            if(cnt==n)return true;
        }
        for(int i=0;i<s.length();i++){
            string tmp=s.substr(0,i+1);
            int req=stoi(tmp);
            if(req<=n){
                if(poss(s.substr(i+1),n, cnt+req))return true;
            }
        }
    return false;
    }
    int punishmentNumber(int n) {
//          int punishment = 0;
    
//     for (int i = 1; i <= n; i++) {
//         int square = i * i;
//         std::string squareStr = std::to_string(square);
//         int sum = 0;
//         bool isValid = true;
        

    // return punishment;
        vector<int>dp(1001,0);
        for(int i=1;i<=1000;i++){
            string temp=to_string(i*i);
            if(poss(temp,i,0))dp[i]=1;
        }
        dp[1]=1;
        dp[9]=1;
        int cnt=0;
        for(int i=1;i<=n;i++)if(dp[i])cnt+=i*i;
        // ifn>10)
        return cnt;
    }
};