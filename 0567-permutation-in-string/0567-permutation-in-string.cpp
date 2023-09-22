class Solution {
public:
    bool checkInclusion(string s1, string s2) {
     vector<int>goal(26,0);
        vector<int>curr(26,0);
        int k = s1.length(),l=s2.length();
        int r=0;
        for(char c :s1){goal[c-'a']++;}
        while(r<l){
           curr[s2[r]-'a']++;
            if(r>=k){
               curr[s2[r-k]-'a']--;
            }
            r++;
            if(goal==curr)return true;
        }
        return false;
    }
};