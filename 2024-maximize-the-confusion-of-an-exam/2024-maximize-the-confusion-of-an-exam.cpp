class Solution {
public:
    int atmostofchar(string s,char a,int k){
        int l=0,cnt=0,res=INT_MIN,n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]==a)cnt++;
            while(cnt>k){/*THIS IS TO ENSURE THAT THERE WONT BE MORE THAN 'K' CHARS CONSECUTIVELY i.e AT-MOST 'K' CHAR A */
                if(s[l]==a)cnt--;
                l++;
            }
            res=max(res,i-l+1);
        }
        return res;
    }
    int maxConsecutiveAnswers(string s, int k) {
       return max(atmostofchar(s,'F',k),atmostofchar(s,'T',k));
    }
};