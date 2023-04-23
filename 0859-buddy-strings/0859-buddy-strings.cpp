class Solution {
public:
    bool buddyStrings(string A, string B) {
        int n=A.length(),m=B.length();
        if(n!=m)return false;
        // unordered_map<char,int>mp;
        // for(int i=0;i<m;i++){
        //     mp[s[i]]=i;
        // }
        // unordered_set<char>s1(s.begin(),s.end());
        // unordered_set<char>s2(goal.begin(),goal.end());
        // if(s==goal&&s1.size()==s2.size())return true;
        // bool done=0;
        // for(int i=0;i<n;i++){
        //     if(s[i]!=goal[i]){
        //         if(mp.find(goal[i])!=mp.end()){
        //             swap(s[mp[goal[i]]],s[i]);
        //             done=1;
        //             break;
        //         }
        //     }
        // }
        // BF wont work 
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         swap(s[i],s[j]);
        //         if(s==goal)return true;
        //         else{
        //             swap(s[i],s[j]);
        //         }
        //     }
        // }
        
        if (A.length() != B.length()) return false;
        if (A == B && set<char>(A.begin(), A.end()).size() < A.size()) return true;
        vector<int> dif;
        for (int i = 0; i < A.length(); ++i) if (A[i] != B[i]) dif.push_back(i);
        return dif.size() == 2 && A[dif[0]] == B[dif[1]] && A[dif[1]] == B[dif[0]];
    return false;}
};